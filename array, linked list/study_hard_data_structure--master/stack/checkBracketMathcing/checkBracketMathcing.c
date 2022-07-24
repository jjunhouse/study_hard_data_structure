#include "../linkedstack/linkedstack.h"

int	isOpenBracket(StackNode node)
{
	char	c;

	c = node.data;
	if (c == '(' || c == '{' || c == '[')
		return (TRUE);
	return (FALSE);
}

int	isCloseBracket(StackNode node)
{
	char	c;

	c = node.data;
	if (c == ')' || c == '}' || c == ']')
		return (TRUE);
	return(FALSE);
}

int	checkBracketPairs(LinkedStack *stack, StackNode node)
{
	StackNode	*peek;

	if (isLinkedStackEmpty(stack))
		return (FALSE);
	peek = peekLS(stack);
	if (peek->data == '(' && node.data == ')')
	{
		popLS(stack);
		return (TRUE);

	}
	else if (peek->data == '{' && node.data == '}')
	{
		popLS(stack);
		return (TRUE);

	}
	else if (peek->data == '[' && node.data == ']')
	{
		popLS(stack);
		return (TRUE);
	}
	else
		return (FALSE);
	return (FALSE);
}

int checkBracketMatching(char *expr)
{
	int				i;
	int				result;
	StackNode		node;
	LinkedStack		*stack;

	i = 0;
	result = TRUE;
	stack = createLinkedStack();
	while (*(expr + i) != '\0' && result != FALSE)
	{
		node.data = *(expr + i);
		if (isOpenBracket(node))
		{
			pushLS(stack, node);
		}
		else if (isCloseBracket(node))
		{
			result = checkBracketPairs(stack, node);
		}
		i += 1;
	}
	if (!isLinkedStackEmpty(stack))
		return (FALSE);
	return (result);
}

// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	if (argc >= 2)
// 	{
// 		printf("string: %s\n, result: %d", argv[1], checkBracketMatching(argv[1]));
// 	}
// 	return (0);
// }