#include "circular_linked_list.h"

int removeCLElement(CircularList* pList, int position)
{
	int					i;
    int					currNodeCount;
	CircularListNode	*prevNode;
	CircularListNode	*currNode;
	CircularListNode	*tailNode;

    currNodeCount = pList->currentElementCount;
    if (!pList || position < 0 || position >= currNodeCount) 
        return (FALSE);
	i = 0;
	prevNode = NULL;
	currNode = pList->headerNode.pLink;
	tailNode = getTailNode(pList, currNodeCount);
	while (i < position)
	{
		prevNode = currNode;
		currNode = currNode->pLink;
		i += 1;
	}
	if (!prevNode)
	{
		pList->headerNode.pLink = currNode->pLink;  // 다음 노드와 헤더 노드를 연결
		tailNode->pLink = currNode->pLink;	       // 마지막 노드를 첫 번째 노드와 연결
	}
	else
	{
		prevNode->pLink = currNode->pLink;
	}
	currNode->pLink = NULL;					   // 현재 노드의 링크 끊기
	free(currNode);							   // 현재 노드 메모리 해제
	pList->currentElementCount -= 1;
    return (TRUE);
}

int	main(void)
{
	CircularList		*list;
	CircularListNode	node1;
	CircularListNode	node2;
	CircularListNode	node3;

	list = createCircularList();
	node1.data = 1;
	node2.data = 2;
	node3.data = 3;

	addCLElement(list, 0, node1);		// TRUE [1]
	addCLElement(list, 1, node2);		// TRUE [1, 2]
	addCLElement(list, 1, node3);		// TRUE [1, 3, 2]

	removeCLElement(list, 1);			// TRUE [1, 2]
	removeCLElement(list, 1);			// TRUE [1]

	return (0);
}