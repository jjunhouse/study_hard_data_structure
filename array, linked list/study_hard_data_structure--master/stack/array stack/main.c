#include "arraystack.h"
#include <stdio.h>

int main(void)
{
    // ArrayStack  *haniStack1;
    // ArrayStackNode  haniStackNode1;

    // haniStack1 = createArrayStack(5);

    // if (isArrayStackFull(haniStack1) == TRUE)
    //     printf("FULL=꽉차있대\n");
    // else
    //     printf("FULL=비어있대\n");
    
    // if (isArrayStackEmpty(haniStack1) == TRUE)
    //     printf("empty == 비어있대\n");
    // else
    //     printf("empty == 뭐가있나벼\n");

    // haniStackNode1.data = 3;
    // pushLS(haniStack1, haniStackNode1);
    // printf("peek result = %d\n", peekLS(haniStack1)->data);

    // if (isArrayStackEmpty(haniStack1) == TRUE)
    //     printf("empty == 비어있대\n");
    // else
    //     printf("empty == 뭐가있나벼\n");

    // ArrayStackNode *tmp;
    // tmp = peekLS(haniStack1);
    // if (peekLS(haniStack1)->data == 3)
    //     printf("push잘들어갔슈\n");
    // else
    //     printf("%d\n", peekLS(haniStack1)->data);
    //     //printf("push망해쓔\n");
    
    // tmp = popLS(haniStack1);
    // if (tmp->data == 0)
    //     printf("pop망해쓔\n");
    // else
    //     printf("pop잘나갔슈\n");
    
    
    // if (isArrayStackEmpty(haniStack1) == TRUE)
    //     printf("empty == 비어있대\n");
    // else
    //     printf("empty == 뭐가있나벼\n");
    
    // return (0);

    ArrayStack *pStack;
	ArrayStackNode element;
	element.data = 0;
	pStack = createArrayStack(10);
	for (int i = 0; i < 11; i++)
	{
		pushLS(pStack, element);
		element.data++;
	}
	if (isArrayStackFull(pStack))
		printf("Stack is FULL!\n");
	printf("peek result = %d\n", peekLS(pStack)->data);
	while (pStack->currentElementCount)
		printf("%d ", popLS(pStack)->data);
	printf("\n");
	if (isArrayStackEmpty(pStack))
		printf("Stack is EMPTY!\n");
	deleteArrayStack(pStack);
	return (0);
}
