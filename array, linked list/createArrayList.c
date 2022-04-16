#include "arraylist.h"
#include <stdio.h>

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList* list;
    ArrayListNode* node;

    if (maxElementCount <= 0)
        return (0);
    list = malloc(sizeof(ArrayList));
    if (!list)
        return (0);
    node = malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!node)
        return (0);
    list->maxElementCount = maxElementCount;
    list->currentElementCount = 0;
    list->pElement = node;
    return (list);
}

int main(void)
{
    int max;
    ArrayList* alist;

    max = 3;
    alist = createArrayList(9999999999);
    printf("%d\n", alist->maxElementCount);
    printf("%p", alist->pElement);

}