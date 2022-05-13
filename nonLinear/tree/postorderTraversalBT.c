#include <stdio.h>
#include "bintree.h"

void    postorderTraversalBT(BinTreeNode *root)
{
    if (root)
    {
        postorderTraversalBT(root->pLeftChild);
        postorderTraversalBT(root->pRightChild);
        printf("%c\n", root->data);
    }
}