#include "linkedstack.h"
#include <stdio.h>

int checkBracketMatching(char *expr);
int	isOpenBracket(StackNode node);
int	isCloseBracket(StackNode node);

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (TRUE);
    return (FALSE);
}

int isHighOperator(char c)
{
    if (c == '*' || c == '/')
        return (TRUE);
    return (FALSE);
}

int isLowOperator(char c)
{
    if (c == '+' || c == '-')
        return (TRUE);
    return (FALSE);
}

void    clearstack(LinkedStack *stack)
{
    int         i;
    StackNode   *pop;

    if (isLinkedStackEmpty(stack))
        return ;
    i = stack->currentElementCount - 1;
    while (i >= 0)
    {
        pop = popLS(stack);
        printf("%c", pop->data);
        i -= 1;
    }
}

int postfix(char *expr)
{
    int         i;
    int         result;
    LinkedStack *stack;
    StackNode   node;
    StackNode   *peek;

    if (!checkBracketMatching(expr))
        return (0);
    i = 0;
    result = TRUE;
    stack = createLinkedStack();
    while (*(expr + i) != '\0' && result != FALSE)
    {
        node.data = *(expr + i);
        if (isLowOperator(node.data))
        {
            if (!isLinkedStackEmpty(stack))
            {
                peek = peekLS(stack);
                    if (isHighOperator(peek->data))
                        clearstack(stack);
            }
            pushLS(stack, node);
        }
        else if (isHighOperator(node.data))
        {
            pushLS(stack, node);
        }
        else if (isOpenBracket(node))
        {
            while (*(expr + i) != '\0' && !isCloseBracket(node))
            {
                node.data = *(expr + i);
                if (isOperator(node.data))
                    pushLS(stack , node);
                else
                {
                    if (!isOpenBracket(node) && !isCloseBracket(node))
                        printf("%c", node.data);
                }
                i += 1;
            }
            clearstack(stack);
            continue ;
        }
        else
        {
            printf("%c", node.data);
        }
        i += 1;
    }
    clearstack(stack);
    return (TRUE);
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        printf("string: %s\n", argv[1]);
        printf("result: %d\n", postfix(argv[1]));
    }
    return (0);
}