#include <stdio.h>
#include "MGraph.h"

void  print_data(MVertex* vertex) {
    printf("%s", (char*)vertex);
}
int main() {
    MVertex* v[] = {"A", "B", "C", "D", "E", "F"};
    MGraph* graph = MGraph_Create(v, sizeof(v) / sizeof(v[0]));

    //MGraph_AddEdge(graph, 0, 1, 1);
    //MGraph_AddEdge(graph, 1, 2, 1);
    //MGraph_AddEdge(graph, 2, 3, 1);
    //MGraph_AddEdge(graph, 2, 4, 1);
    //MGraph_AddEdge(graph, 3, 4, 9);

    MGraph_AddEdge(graph, 0, 1, 1);
    MGraph_AddEdge(graph, 0, 2, 1);
    MGraph_AddEdge(graph, 0, 3, 1);
    MGraph_AddEdge(graph, 1, 5, 1);
    MGraph_AddEdge(graph, 1, 4, 1);
    MGraph_AddEdge(graph, 2, 1, 1);
    MGraph_AddEdge(graph, 3, 4, 1);
    MGraph_AddEdge(graph, 4, 2, 1);

    printf("Weight <D,E>: %d\n", MGraph_GetEdge(graph, 3, 4));
    printf("Vertex Count: %d\n", MGraph_VertexCount(graph));
    printf("Edge Count: %d\n", MGraph_EdgeCount(graph));
    printf("Degree C: %d\n", MGraph_TD(graph, 2));
    MGraph_Display(graph, print_data);

    printf("------------DFS ------------------------------\n");
    MGraph_DFS(graph, 0, print_data);
    printf("\n");

    MGraph_Clear(graph);
    printf("------------After Clear------------------------------\n");
    printf("Weight <D,E>: %d\n", MGraph_GetEdge(graph, 3, 4));
    printf("Vertex Count: %d\n", MGraph_VertexCount(graph));
    printf("Edge Count: %d\n", MGraph_EdgeCount(graph));
    printf("Degree C: %d\n", MGraph_TD(graph, 2));
    MGraph_Display(graph, print_data);

    MGraph_Destroy(graph);
    return 0;
}
