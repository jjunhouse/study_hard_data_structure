//displayArrayList
#include "arraylist.h"
#include <stdio.h>

void displayArrayList(ArrayList* pList)
{
	int	max;
	int	cur;
	ArrayListNode	*arr;

	max = pList->maxElementCount;
	cur = pList->currentElementCount;
	arr = pList->pElement;
	
	printf("max%d\n", max);
	printf("cur%d\n", cur);
	for(int i=0; i < cur; i++)
	{
		printf("%d", (arr + i)->data);
		if (i != cur - 1)
			printf(", ");
	}				
	printf("\n");
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

	displayArrayList(arr);

	return (0);
}