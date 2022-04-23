// clearArrayList.c
#include "arraylist.h"

void	clearArrayList(ArrayList *pList)
{
	int		curr;
	ArrayListNode	*arr;

	curr = getArrayListLength(pList);
	arr = pList->pElement;
	for (int i = 0; i < curr; i++)
		(arr + i)->data = 0;
	pList->currentElementCount = 0;
}

int	main(void)
{
	int		size;
	ArrayList	*arr;
	ArrayListNode	node;
	ArrayListNode	node2;
	ArrayListNode	node3;
	ArrayListNode	node4;

	size = 5;
	node.data = 1;
	node2.data = 2;
	node3.data = 3;
	node4.data = 4;
	arr = createArrayList(size);

	addALElement(arr, 8, node);   // [1]
	addALElement(arr, 1, node2);  // [1, 2]
	addALElement(arr, 0, node3);  // [3, 1, 2]
	addALElement(arr, -9, node4); // [3, 1, 2]

	clearArrayList(arr);

	return (0);
}