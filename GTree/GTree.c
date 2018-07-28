#include <stdio.h>
#include <malloc.h>
#include "GTree.h"
#include "LinkList.h"

typedef struct _tag_GTreeNode GTreeNode;
struct _tag_GTreeNode {
    GTreeData* data;
    GTreeNode* parent;
    LinkList* child;
};

typedef struct _tag_TLNode TLNode;
struct _tag_TLNode {
    LinkListNode header;
    GTreeNode* node;
};

static int recursive_degree(GTreeNode* node) {
    int ret = 0;
    if (node != NULL) {
        ret = LinkList_Length(node->child);
        for (int i = 0;i < LinkList_Length(node->child);i++) {
            TLNode* cNode = (TLNode*)LinkList_Get(node->child, i);
            int degree = recursive_degree(cNode->node) ;
            if (degree > ret) {
                ret = degree;
            }
        }
    }
    return ret;
}

static int recursive_height(GTreeNode* node) {
    int ret = 0;
    if (node != NULL) {
        int subHeight = 0;
        for (int i = 0;i < LinkList_Length(node->child);i++) {
            TLNode* cNode = (TLNode*)LinkList_Get(node->child, i);
            subHeight = recursive_height(cNode->node) ;
            if (subHeight > ret) {
                ret = subHeight;
            }
        }
        ret = ret + 1;
    }
    return ret;
}

static void recursive_display(GTreeNode* node, GTree_Printf pFunc, int deep, int gap, char div) {
    if (node != NULL) {
        for (int i = 0;i < deep * gap;i++) {
            printf("%c", div);
        }
        pFunc(node->data);
        printf("\n");
        for (int i = 0;i < LinkList_Length(node->child);i++) {
            TLNode* trNode = (TLNode*)LinkList_Get(node->child, i);
            recursive_display(trNode->node, pFunc, deep + 1, gap, div);
        }
    }
}

static void recursive_delete(LinkList* list, GTreeNode* node) {
    if (list != NULL && node != NULL) {
        int index = -1;
        //从tree链表中删除
        for (int i = 0;i < LinkList_Length(list);i++) {
            TLNode* tlNode = (TLNode*)LinkList_Get(list, i);
            if (tlNode->node == node) {
                index = i;
                LinkList_Delete(list, i);
                free(tlNode);
                break;
            }
        }
        //从父节点中删除当前节点
        if (index >= 0) {
            GTreeNode* parent = node->parent;
            if (parent != NULL) {
                for (int i = 0;i < LinkList_Length(parent->child);i++) {
                    TLNode* trNode = (TLNode*)LinkList_Get(parent->child, i);
                    if (trNode->node == node) {
                        LinkList_Delete(parent->child, i);
                        free(trNode);
                        break;
                    }
                }
            }
            //删除子节点
            while (LinkList_Length(node->child) > 0) {
                TLNode* trNode = (TLNode*)LinkList_Get(node->child, 0);
                recursive_delete(list, trNode->node);
            }
            //删除当前节点
            LinkList_Destroy(node->child);
            free(node);
        }
    }
}

GTree* GTree_Create() {
    return LinkList_Create();
}

void GTree_Destroy(GTree* tree) {
    GTree_Clear(tree);
    LinkList_Destroy(tree);
}

void GTree_Clear(GTree* tree) {
    GTree_Delete(tree, 0);
}

int GTree_Insert(GTree* tree, GTreeData* data, int pPos) {
    LinkList* list = (LinkList*)tree;
    int ret = (list != NULL) && (data != NULL) && (pPos < LinkList_Length(list));
    if (ret) {
        //申请一个树节点
        GTreeNode* tNode = (GTreeNode*)malloc(sizeof(GTreeNode));
        //根据pPos取父节点
        TLNode* pNode = (TLNode*)LinkList_Get(list, pPos);
        //申请一个tree链表节点
        TLNode* tlNode = (TLNode*)malloc(sizeof(TLNode));
        //申请一个child链表节点
        TLNode* trNode = (TLNode*)malloc(sizeof(TLNode));
        ret = (tNode != NULL) && (tlNode != NULL) && (trNode != NULL);
        if (ret) {
            tNode->data = data;
            tNode->parent = NULL;
            tNode->child  = LinkList_Create();

            tlNode->node = tNode;
            trNode->node = tNode;

            LinkList_Insert(list, (LinkListNode*)tlNode, LinkList_Length(list));
            if (pNode != NULL) {
                tNode->parent = pNode->node;
                LinkList_Insert(pNode->node->child, (LinkListNode*)trNode, LinkList_Length(pNode->node->child));
            }
        } else {
            free(tNode);
            free(tlNode);
            free(trNode);
        }
    }
    return ret;
}

GTreeData* GTree_Delete(GTree* tree, int pPos) {
    GTreeData* ret = NULL;
    TLNode* pNode = (TLNode*)LinkList_Get(tree, pPos);
    if (pNode != NULL) {
        ret = pNode->node->data;
        recursive_delete(tree, pNode->node);
    }
    return ret;
}

GTreeData* GTree_Get(GTree* tree, int pos) {

    return NULL;
}

GTreeData* GTree_Root(GTree* tree) {
    GTreeData* data = NULL;
    TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
    if (trNode != NULL) {
        data = trNode->node->data;
    }
    return data;
}

int GTree_Height(GTree* tree) {
    TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
    return recursive_height(trNode->node);
}

int GTree_Count(GTree* tree) {
    return LinkList_Length(tree);
}

int GTree_Degree(GTree* tree) {
	int ret = 0;
    TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
    if (trNode != NULL) {
        ret = recursive_degree(trNode->node);
    }
	return ret;
}

void GTree_Display(GTree* tree, GTree_Printf* pFunc, int gap, char div) {
    TLNode* trNode = (TLNode*)LinkList_Get(tree, 0);
    if (trNode != NULL) {
        recursive_display(trNode->node, pFunc, 0, gap, div);
    }
}


