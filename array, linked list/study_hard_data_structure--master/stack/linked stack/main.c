#include "linkedstack.h"
#include <stdio.h>

int	main(void)
{
	LinkedStack	*stack;
	StackNode	node1;
	StackNode	node2;
	StackNode	node3;
	StackNode	*peek;
	StackNode	*pop;

	stack = createLinkedStack();
	node1.data = 'a';
	node2.data = 'b';
	node3.data = 'c';

	pushLS(stack, node1);
	pushLS(stack, node2);
	pushLS(stack, node3);
    displayStack(stack);

	// peek = peekLS(stack);
    // printf("%c\n", peek->data);
    //free(peek);
    // pop = popLS(stack);
    // printf("%c\n", pop->data);
    //free(pop);
	// displayStack(stack);
    deleteLinkedStack(stack);
	displayStack(stack);
	system("leaks a.out");
	return (0);
}