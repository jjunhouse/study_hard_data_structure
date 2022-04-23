// getArrayListLength.c

#include "arraylist.h"

int	getArrayListLength(ArrayList *pList)
{
	return (pList->currentElementCount);
}

int	main(void)
{
	int		size;
	ArrayList	*arr;
	ArrayListNode	node;
	ArrayListNode	node2;
	ArrayListNode	node3;
	ArrayListNode	node4;
	int		length;


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

	length = getArrayListLength(arr);
	return (0);
}