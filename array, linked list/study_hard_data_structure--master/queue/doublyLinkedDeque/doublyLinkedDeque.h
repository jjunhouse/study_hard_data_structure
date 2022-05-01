#ifndef _DOUBLY_LINKED_DEQUE_
#define _DOUBLY_LINKED_DEQUE_

#include <stdio.h>
#include <stdlib.h>

typedef	enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
} t_flag;

typedef struct DequeNodeType
{
	char 					data;
	struct DequeNodeType	*pRLink;
	struct DequeNodeType	*pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int 		currentElementCount;
	DequeNode	*pFrontNode;
	DequeNode	*pRearNode;
} LinkedDeque;

LinkedDeque* createLinkedDeque();

int 		insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int 		insertRearLD(LinkedDeque* pDeque, DequeNode element);

DequeNode	*deleteFrontLD(LinkedDeque* pDeque);
DequeNode	*deleteRearLD(LinkedDeque* pDeque);
DequeNode	*peekFrontLD(LinkedDeque* pDeque);
DequeNode	*peekRearLD(LinkedDeque* pDeque);

void 		deleteLinkedDeque(LinkedDeque* pDeque);

int 		isLinkedDequeEmpty(LinkedDeque* pDeque);


//additional
int	NULLCHECK(void *ptr);

#endif
