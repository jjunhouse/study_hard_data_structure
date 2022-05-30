#include "linkedQueue.h"

int	NULLCHECK(void *ptr)
{
	if (!ptr)
	{
		printf("NULL pointer exception\n");
		return (TRUE);
	}
	return (FALSE);
}