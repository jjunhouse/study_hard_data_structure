// deleteArrayList.c
#include "arraylist.h"

void	deleteArrayList(ArrayList* pList)
{
	if (!pList)
		return ;
	free(pList->pElement);
	free(pList);
}

int	main(void)
{
	ArrayList	*list;
	int		size;

	size = 4;
	list = createArrayList(size);
	deleteArrayList(list);
	system("leaks a.out");
	return (0);
}