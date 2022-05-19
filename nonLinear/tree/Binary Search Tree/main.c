#include <stdlib.h>
#include "binsearchtree.h"
#include <stdio.h>

int	main(void)
{
	BSTreeNode	*root;
	BSTreeNode	element;

	root = newnode(50);
	element.data = 30;
	insertChildNodeBST(root, element);
	element.data = 70;
	insertChildNodeBST(root, element);
	element.data = 15;
	insertChildNodeBST(root, element);
	element.data = 40;
	insertChildNodeBST(root, element);
	element.data = 60;
	insertChildNodeBST(root, element);
	element.data = 90;
	insertChildNodeBST(root, element);
	/*element.data = 10;
	insertChildNodeBST(root, element);
	element.data = 24;
	insertChildNodeBST(root, element);
	element.data = 26;
	insertChildNodeBST(root, element);
	element.data = 55;
	insertChildNodeBST(root, element);
	element.data = 80;
	insertChildNodeBST(root, element);*/
	preorder(root);
	deleteBSTreeNode(root, 90);
	deleteBSTreeNode(root, 40);
	deleteBSTreeNode(root, 15);
	deleteBSTreeNode(root, 30);
	printf("%d", root);
	//deleteBSTreeNode(tree, root, 15);
	//deleteBSTreeNode(tree, root, 60);
}
