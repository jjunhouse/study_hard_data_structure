#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

typedef struct	BinSearchNodeType
{
	int							data;
	struct BinSearchNodeType	*pLeftChild;
	struct BinSearchNodeType	*pRightChild;
}	BSTreeNode;

typedef struct	BinSearchTreeType
{
	BSTreeNode	*pRootNode;
}	BSTree;

BSTreeNode	*newnode(int k);
BSTree		*makeBinSearchTree(BSTreeNode RootNode);
BSTreeNode	*getRootNodeBST(BSTree *pBSTree);
BSTreeNode	*searchChildNodeBSTrec(BSTreeNode *pRootNode, BSTreeNode element);
BSTreeNode	*searchChildNodeBSTite(BSTree *pBSTree, BSTreeNode element);
BSTreeNode	*searchminValueNode(BSTreeNode *pRootNode);
BSTreeNode	*insertChildNodeBST(BSTreeNode *pRootNode, BSTreeNode element);
void		deleteBSTree(BSTree *pBSTree);
BSTreeNode	*deleteBSTreeNode(BSTreeNode *pRootNode, int element);
void		preorder(BSTreeNode *pRootNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE	1
#define FALSE	0

#endif
