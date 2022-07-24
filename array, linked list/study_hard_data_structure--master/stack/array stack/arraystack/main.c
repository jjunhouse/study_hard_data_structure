#include "arraystack.h"
#include <stdio.h>

int main(void)
{
	int				size;
    ArrayStack      *stack;
    ArrayStackNode  node1;
    ArrayStackNode  node2;
    ArrayStackNode  node3;
    ArrayStackNode  node4;
    ArrayStackNode  *peek;
    ArrayStackNode*  pop;
    int  result;

	size = 3;
	node1.data = 'a'; // 0
	node2.data = 'b'; // 1
	node3.data = 'c'; // 2
	node4.data = 'd'; // 3

	stack = createArrayStack(size);

	pushAS(stack, node1);		// TRUE ['a']
	pushAS(stack, node2);		// TRUE ['a', 'b']
	pushAS(stack, node3);		// TRUE ['a', 'b', 'c']
	// printf("isArrayStackFull : %d\n", isArrayStackFull(stack));
	// printf("isArrayStackEmpty: %d\n", isArrayStackEmpty(stack));
	// result = pushAS(stack, node4);		// FALSE
	// printf("%d\n", result);
	pop = popAS(stack);
    // displayArrayStack(stack);
    // printf("-------------------------\n");
	// peek = peekAS(stack);
    displayArrayStack(stack);     // 'a' 'b'
    // printf("peek : %c\n", peek->data);  // 'b'
    // printf("pop  : %c\n", pop);   // 'c'
	deleteArrayStack(stack);
	system("leaks a.out");
    return (0);
}