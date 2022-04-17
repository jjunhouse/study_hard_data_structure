// deleteArrayList.c
#include "arraylist.h"

void	deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	free(pList->pElement);
	free(pList);
}

