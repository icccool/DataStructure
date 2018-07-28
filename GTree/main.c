#include <stdio.h>
#include "GTree.h"

void  printf_data(GTreeData* data) {
    printf("%c", (int)data);
}

int main() {
    GTree* tree = GTree_Create();
    GTree_Insert(tree, (GTreeData*)'A', -1); //0
    GTree_Insert(tree, (GTreeData*)'B', 0);  //1
    GTree_Insert(tree, (GTreeData*)'C', 0);  //2
    GTree_Insert(tree, (GTreeData*)'D', 0);  //3
    GTree_Insert(tree, (GTreeData*)'E', 1);  //4
    GTree_Insert(tree, (GTreeData*)'F', 1);  //5
    GTree_Insert(tree, (GTreeData*)'G', 4);  //6
    GTree_Insert(tree, (GTreeData*)'H', 5);  //7
    GTree_Insert(tree, (GTreeData*)'I', 3);  //8
    GTree_Insert(tree, (GTreeData*)'J', 4);  //9
    GTree_Insert(tree, (GTreeData*)'K', 9);  //10
    GTree_Insert(tree, (GTreeData*)'L', 10);
    GTree_Insert(tree, (GTreeData*)'M', 10);
    GTree_Insert(tree, (GTreeData*)'N', 10);
    GTree_Insert(tree, (GTreeData*)'O', 10);

    printf("Tree Height: %d\n", GTree_Height(tree));
    printf("Tree Degree: %d\n", GTree_Degree(tree));

    printf("Full Tree:\n");
    GTree_Display(tree, printf_data, 1, '.');

    GTree_Delete(tree, 1);
    printf("After Deleting B:\n");
    GTree_Display(tree, printf_data, 1, '.');

    //printf("After Clearing Tree:\n");
    //GTree_Display(tree, printf_data, 2, '-');

    GTree_Destroy(tree);
    return 0;
}
