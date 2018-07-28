#include <stdio.h>
#include <malloc.h>
#include "BTree.h"

typedef struct _tag_BTree TBTree;
struct _tag_BTree {
    BTreeNode *root;
    int count;
};

static int recursive_height(BTreeNode* node) {
    int ret = 0;
    if (node != NULL) {
        int lt = recursive_height(node->left) + 1;
        int rt = recursive_height(node->right) + 1;
        if (lt >= rt) {
            ret = lt;
        } else {
            ret = rt;
        }
    }
    return ret;
}

static int recursive_count(BTreeNode* node) {
    int ret = 0;
    if (node != NULL) {
        ret =  recursive_count(node->left) + 1 + recursive_count(node->right);
    }
    return ret;
}
static int recursive_degree(BTreeNode* node) {
    int ret = 0;
    if (node != NULL) {
        if (node->left != NULL) {
            ret++;
        }
        if (node->right != NULL) {
            ret++;
        }
        if (ret == 1) {
            int lt = recursive_degree(node->left);
            int rt = recursive_degree(node->right);
            if (ret < lt) {
                ret = lt;
            }
            if (ret < rt) {
                ret = rt;
            }
        }
    }
    return ret;
}

static void recursive_display(BTreeNode* node, BTree_Printf pFunc, int fmt, int gap, int div) {
    if (node != NULL) {
        for (int i = 0;i < fmt;i++) {
            printf("%c", div);
        }
        pFunc(node);
        printf("\n");
        if (node->left != NULL || node->right != NULL) {
            recursive_display(node->left, pFunc, fmt + gap, gap, div);
            recursive_display(node->right, pFunc, fmt + gap, gap, div);
        }
    } else {
        for (int i = 0;i < fmt;i++) {
            printf("%c", div);
        }
        printf("\n");
    }
}

BTree* BTree_Create() {
    TBTree* tree = (TBTree*)malloc(sizeof(BTree));
    if (tree != NULL) {
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

void BTree_Destroy(BTree* tree) {
    free(tree);
}

void BTree_Clear(BTree* tree) {
    TBTree* btree = (TBTree*)tree;
    if (btree != NULL) {
        btree->root = NULL;
        btree->count = 0;
    }
}

int BTree_Insert(BTree* tree, BTreeNode* node, BTPos pos, int count, int flag) {
    TBTree* btree = (TBTree*)tree;
    int ret = (btree != NULL) && (pos >= 0) && (node != NULL);
    if (ret) {
        BTreeNode* parent = NULL;
        BTreeNode* current = btree->root;
        int bit = 0;
        int count = btree->count;
        while (count > 0 && current != NULL) {
            bit = pos & 1;
            pos = pos >> 1;
            parent  = current;
            if (bit == BT_LEFT) {
                current = current->left;
            } else if (bit == BT_RIGHT) {
                current = current->right;
            }
            count--;
        }

        if (flag == BT_LEFT) {
            node->left = current;
        } else if (flag == BT_RIGHT) {
            node->right = current;
        }

        if (parent != NULL) {
            if (bit == BT_LEFT) {
                parent->left = node;
            } else if (bit == BT_RIGHT) {
                parent->right = node;
            }
        } else {
            btree->root = node;
        }
        btree->count++;
    }
    return ret;
}

BTreeNode* BTree_Delete(BTree* tree, BTPos pos, int count) {
    TBTree* btree = (TBTree*)tree;
    BTreeNode* ret = NULL;
    if (btree != NULL) {
        int bit = 0;
        BTreeNode* parent = NULL;
        BTreeNode* current = btree->root;
        while (count > 0 && current != NULL) {
            bit = pos & 1;
            pos = pos >> 1;
            parent = current;
            if (bit == BT_LEFT) {
                current = current -> left;
            } else if (bit == BT_RIGHT) {
                current = current -> right;
            }
            count--;
        }
        if (parent != NULL) {
            if (bit == BT_LEFT) {
                parent -> left = NULL;
            } else if (bit == BT_RIGHT) {
                parent -> right = NULL;
            }
        } else {
            btree -> root = NULL;
        }
        ret = current;
        btree -> count -= recursive_count(ret);
    }
    return ret;
}

BTreeNode* BTree_Get(BTree* tree, BTPos pos, int count) {
    TBTree* btree = (TBTree*)tree;
    BTreeNode* ret = NULL;
    if (btree != NULL) {
        int bit = 0;
        BTreeNode* current = btree->root;
        while (count > 0 && current != NULL) {
            bit = pos & 1;
            pos = pos >> 1;
            if (bit == BT_LEFT) {
                current = current->left;
            } else if (bit == BT_RIGHT) {
                current = current->right;
            }
            count--;
        }
        ret = current;
    }
    return ret;
}

BTreeNode* BTree_Root(BTree* tree) {
    TBTree* btree = (TBTree*)tree;
    BTreeNode* ret = NULL;
    if (btree != NULL) {
        ret = btree->root;
    }
    return ret;
}

int BTree_Height(BTree* tree) {
    TBTree* btree = (TBTree*)tree;
    int ret = 0;
    if (btree != NULL) {
        ret = recursive_height(btree->root);
    }
    return ret;
}

int BTree_Count(BTree* tree) {
    TBTree* btree = (TBTree*)tree;
    int ret = 0;
    if (btree != NULL) {
        ret = btree->count;
    }
    return ret;
}

int BTree_Degree(BTree* tree) {
    TBTree* btree = (TBTree*)tree;
    int ret = 0;
    if (btree != NULL) {
        ret = recursive_degree(btree->root);
    }
    return ret;
}

void BTree_Display(BTree* tree, BTree_Printf* pFunc, int gap, char div) {
    TBTree* btree = (TBTree*)tree;
    if (btree != NULL) {
        recursive_display(btree->root, pFunc, 0, gap, div);
    }
}
