#include <stdio.h>
#include "bintree.h"

void    inorderTraversalBT(BinTreeNode *root)
{
    if (root)
    {
        inorderTraversalBT(root->pLeftChild);
        printf("%c\n", root->data);
        inorderTraversalBT(root->pRightChild);
    }
}