#include <stdio.h>
#include <malloc.h>
#include "MGraph.h"
#include "linkqueue.h"

//G的邻接矩阵表示
typedef struct _tag_MGraph {
    int count;
    MVertex** v;
    int** matrix;
} TMGraph;

static void bfs(TMGraph* graph, int v, int* visied, MGraph_Printf* pFunc) {
	
}

static void revursive_dfs(TMGraph* graph, int v, int* visied, MGraph_Printf* pFunc) {
    pFunc(graph->v[v]);
    visied[v] = 1;
    printf(", ");
    for (int i = 0;i < graph->count;i++) {
        if (graph->matrix[v][i] != 0 && !visied[i]) {
            revursive_dfs(graph, i, visied, pFunc);
        }
    }
}

MGraph* MGraph_Create(MVertex** v, int n) {
    TMGraph* ret = (TMGraph*)malloc(sizeof(TMGraph));
    int condition = (ret != NULL) && (v != NULL) && (n >= 0);
    if (condition) {
        ret->count = n;
        ret->v = (MVertex**)malloc(sizeof(MVertex*) * n);
        ret->matrix = (int**)malloc(sizeof(int*) * n);
        int* p = (int*)calloc(n * n, sizeof(int));
        if ((ret->v != NULL) && (ret->matrix != NULL) && (p != NULL)) {
            for (int i = 0;i < n;i++) {
                ret->v[i] = v[i];
                ret->matrix[i] = p + i * n;
            }
        } else {
            free(ret->v);
            free(ret->matrix);
            free(p);
            free(ret);
            ret = NULL;
        }
    }
    return ret;
}

void MGraph_Destroy(MGraph* graph) {
    TMGraph* tGraph = (TMGraph*)graph;
    if (tGraph != NULL) {
        free(tGraph->v);
        free(tGraph->matrix[0]); //free(p);
        free(tGraph->matrix);
        free(tGraph);
    }
}

void MGraph_Clear(MGraph* graph) {
    TMGraph* tGraph = (TMGraph*)graph;
    if (tGraph != NULL) {
        for (int i = 0;i < tGraph->count;i++) {
            for (int j = 0;j < tGraph->count;j++) {
                tGraph->matrix[i][j] = 0;
            }
        }
    }
}

int MGraph_AddEdge(MGraph* graph, int v1, int v2, int w) {
    TMGraph* tGraph = (TMGraph*)graph;
    int ret =  (tGraph != NULL);
    ret = ret && (0 <= v1) && (v1 < tGraph->count);
    ret = ret && (0 <= v2) && (v2 < tGraph->count);
    ret = ret && (0 <= w);
    if (ret) {
        tGraph->matrix[v1][v2] = w;
    }
    return ret;
}

int MGraph_RemoveEdge(MGraph* graph, int v1, int v2) {
    int ret = MGraph_GetEdge(graph, v1, v2);
    if (ret != 0) {
        ((TMGraph*)graph)->matrix[v1][v2] = 0;
    }
    return ret;
}

int MGraph_GetEdge(MGraph* graph, int v1, int v2) {
    int ret = 0;
    TMGraph* tGraph = (TMGraph*)graph;
    int condition = (tGraph != NULL);
    condition = condition && (0 <= v1) && (v1 < tGraph->count);
    condition = condition && (0 <= v2) && (v2 < tGraph->count);
    if (condition) {
        ret = tGraph->matrix[v1][v2];
    }
    return ret;
}

//ID 入度 + OD 出度
int MGraph_TD(MGraph* graph, int v) {
    int ret = 0;
    TMGraph* tGraph = (TMGraph*)graph;
    int condition = (tGraph != NULL) && ( 0 <= v) && (v < tGraph->count);
    if (condition) {
        for (int i = 0;i < tGraph->count;i++) {
            if (tGraph->matrix[v][i] != 0) {
                ret++;
            }
            if (tGraph->matrix[i][v] != 0) {
                ret++;
            }
        }
    }
    return ret;
}

int MGraph_VertexCount(MGraph* graph) {
    int ret = 0;
    TMGraph* tGraph = (TMGraph*)graph;
    if (tGraph != NULL) {
        ret = tGraph->count;
    }
    return ret;
}

int MGraph_EdgeCount(MGraph* graph) {
    int ret = 0;
    TMGraph* tGraph = (TMGraph*)graph;
    if (tGraph != NULL) {
        for (int i = 0;i < tGraph->count;i++) {
            for (int j = 0;j < tGraph->count;j++) {
                if (tGraph->matrix[i][j] != 0) {
                    ret++;
                }
            }
        }
    }
    return ret;
}

//Depth First Search
void MGraph_DFS(MGraph* graph, int v, MGraph_Printf* pFunc) {
    TMGraph* tGraph = (TMGraph*)graph;
    int* visied = (int*)calloc(tGraph->count, sizeof(int));
    int condition = (tGraph != NULL);
    condition = (0 <= v) && (v < tGraph->count);
    condition = condition && (pFunc != NULL) && (visied != NULL);
    if (condition) {
        revursive_dfs(tGraph, v, visied, pFunc);
        for (int i = 0;i < tGraph->count;i++) {
            if (!visied[i]) {
                revursive_dfs(tGraph, i, visied, pFunc);
            }
        }
    }
    free(visied);
}

//Beadth First Search
void MGraph_BFS(MGraph* graph, int v, MGraph_Printf* pFunc) {
    TMGraph* tGraph = (TMGraph*)graph;
    int* visied = (int*)calloc(tGraph->count, sizeof(int));
    int condition = (tGraph != NULL);
    condition = (0 <= v) && (v < tGraph->count);
    condition = condition && (pFunc != NULL) && (visied != NULL);
    if (condition) {
        bfs(tGraph, v, visied, pFunc);
        for (int i = 0;i < tGraph->count;i++) {
            if (!visied[i]) {
                bfs(tGraph, i, visied, pFunc);
            }
        }
    }
    free(visied);
}

void MGraph_Display(MGraph* graph, MGraph_Printf* pFunc) {
    TMGraph* tGraph = (TMGraph*)graph;
    if (tGraph != NULL && pFunc != NULL) {
        for (int i = 0;i < tGraph->count;i++) {
            printf("(");
            printf("%d:", i);
            pFunc(tGraph->v[i]);
            printf(") ");
        }
        printf("\n");
        for (int i = 0;i < tGraph->count;i++) {
            for (int j = 0;j < tGraph->count;j++) {
                if (tGraph->matrix[i][j]) {
                    printf("<");
                    pFunc(tGraph->v[i]);
                    printf(",");
                    pFunc(tGraph->v[j]);
                    printf(",");
                    printf("%d", tGraph->matrix[i][j]);
                    printf("> ");
                }
            }
        }
        printf("\n");
    }
}
