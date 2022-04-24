#include "circular_linked_list.h"

CircularListNode* getCLElement(CircularList* pList, int position)
{
	int                 i;
    int                 listLength;
	CircularListNode    *currNode;

    listLength = getCircularListLength(pList);
    if (!pList || position < 0 || position >= listLength)
        return (NULL);
    i = 0;
    currNode = pList->headerNode.pLink;
    while (i < position)
    {
        currNode = currNode->pLink;
        i += 1;
    }
    return (currNode);
}