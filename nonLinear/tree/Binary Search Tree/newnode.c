#include <stdlib.h>
#include "binsearchtree.h"

BSTreeNode	*newnode(int k)
{
	BSTreeNode	*p = malloc(sizeof(BSTreeNode));

	p->pLeftChild = 0;
	p->pRightChild = 0;
	p->data = k;
	return (p);
}
