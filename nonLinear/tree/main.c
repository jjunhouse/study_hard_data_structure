#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(void)
{
    BinTree     *tree;
    BinTreeNode *root;
    BinTreeNode *LChild;
    BinTreeNode *RChild;
    BinTreeNode element;

    root = malloc(sizeof(BinTreeNode));
    if (!root)
        return (0);
    root->data = 'a';
    root->visited = 0;
    root->pLeftChild = 0;
    root->pRightChild = 0;
    tree = makeBinTree(*root);
    element.data = 'b';
    LChild = insertLeftChildNodeBT(root, element);
    element.data = 'c';
    RChild = insertRightChildNodeBT(root, element);
    element.data = 'f';
    insertLeftChildNodeBT(LChild, element);
    element.data = 'g';
    insertRightChildNodeBT(LChild, element);
    element.data = 'j';
    insertLeftChildNodeBT(RChild, element);
    element.data = 'k';
    insertRightChildNodeBT(RChild, element);

    printf("------------------- pre\n");
    PreorderTraversalBT(root);
    printf("------------------- in\n");
    inorderTraversalBT(root);
    printf("------------------- post\n");
    postorderTraversalBT(root);

    deleteBinTree(tree);
    system("leaks a.out");
    return (0);
}