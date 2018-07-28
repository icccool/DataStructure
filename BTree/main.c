#include <stdio.h>
#include "BTree.h"
#include "linkqueue.h"

typedef struct _tag_Node Node;
struct _tag_Node {
    BTreeNode node;
    char data;
};

void printf_data(BTreeNode* node) {
    Node* n = (Node*)node;
    if (n != NULL) {
        printf("%c", n->data);
    }
}


//前序遍历
void pre_order_traversal(BTreeNode* root) {
    if (root != NULL) {
        printf("%c\n", ((Node*)root)->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}
//中序遍历
void in_order_traversal(BTreeNode* root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        printf("%c\n", ((Node*)root)->data);
        in_order_traversal(root->right);
    }
}
//后续遍历
void post_order_traversal(BTreeNode* root) {
    if (root != NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%c\n", ((Node*)root)->data);
    }
}
//层次遍历
void level_order_traversal(BTreeNode* root) {
    if (root != NULL) {
        LinkQueue* queue = LinkQueue_Create();
        if (queue != NULL) {
            LinkQueue_Append(queue, (void*)root);
            while (LinkQueue_Length(queue) > 0) {
                Node* n = (Node*)LinkQueue_Retrieve(queue);
                printf("%c\n", n->data);
                LinkQueue_Append(queue, n->node.left);
                LinkQueue_Append(queue, n->node.right);
            }
        }
    }
}
//线索化二叉树
BTreeNode* p = NULL;
void thread_via_left(BTreeNode* root) {
    if (root != NULL) {
        if (p != NULL) {
            p->left = root;
            p = NULL;
        }
        if (root->left == NULL) {
            p = root;
        }
        thread_via_left(root->left);
        thread_via_left(root->right);
    }
}

int main() {
    BTree* tree = BTree_Create();
    Node n1 = {{NULL, NULL}, 'A'};
    Node n2 = {{NULL, NULL}, 'B'};
    Node n3 = {{NULL, NULL}, 'C'};
    Node n4 = {{NULL, NULL}, 'D'};
    Node n5 = {{NULL, NULL}, 'E'};
    Node n6 = {{NULL, NULL}, 'F'};

    BTree_Insert(tree, (BTreeNode*)&n1, 0, 0, 0);
    BTree_Insert(tree, (BTreeNode*)&n2, 0x00, 1, 0);
    BTree_Insert(tree, (BTreeNode*)&n3, 0x01, 1, 0);
    BTree_Insert(tree, (BTreeNode*)&n4, 0x00, 2, 0);
    BTree_Insert(tree, (BTreeNode*)&n5, 0x02, 2, 0);
    BTree_Insert(tree, (BTreeNode*)&n6, 0x06, 3, 0);

    printf("---------------------------------------------------------\n");
    printf("Height: %d\n", BTree_Height(tree));
    printf("Count: %d\n", BTree_Count(tree));
    printf("Degree: %d\n", BTree_Degree(tree));
    printf("Full Tree:\n");
    printf("Position At (0x02,2): %c \n", ((Node*)BTree_Get(tree, 0x02, 2))->data);
    BTree_Display(tree, printf_data, 1, '-');

    //printf("---------------------------------------------------------\n");
    //printf("pre_order_traversal: \n");
    //pre_order_traversal(BTree_Root(tree));

    //printf("-------------------------------------------------------- \n");
    //printf("in_order_traversal: \n");
    //in_order_traversal(BTree_Root(tree));

    //printf("---------------------------------------------------------\n");
    //printf("post_order_traversal: \n");
    //post_order_traversal(BTree_Root(tree));

    //printf("-------------------------------------------------------- \n");
    //printf("level_order_traversal: \n");
    //level_order_traversal(BTree_Root(tree));

    printf("-------------------------------------------------------- \n");
    printf("thread_via_left: \n");
    thread_via_left(BTree_Root(tree));
    BTreeNode* current = BTree_Root(tree);
    while (current != NULL) {
        Node* node = (Node*)current;
        printf("%c,", node->data);
        current = current->left;
    }
    printf("\n");

    ////delete
    //printf("-------------------------------------------------------- \n");
    //BTree_Delete(tree, 0x00, 1);
    //printf("After Delete B: \n");
    //printf("Height: % d\n", BTree_Height(tree));
    //printf("Degree: % d\n", BTree_Degree(tree));
    //printf("Count: % d\n", BTree_Count(tree));
    //printf("Full Tree: \n");
    //BTree_Display(tree, printf_data, 1, '-');

    ////clear
    //printf("-------------------------------------------------------- \n");
    //BTree_Clear(tree);
    //printf("After Clear: \n");
    //printf("Height: % d\n", BTree_Height(tree));
    //printf("Degree: % d\n", BTree_Degree(tree));
    //printf("Count: % d\n", BTree_Count(tree));
    //BTree_Display(tree, printf_data, 4, '-');

    BTree_Destroy(tree);
    return 0;
}
