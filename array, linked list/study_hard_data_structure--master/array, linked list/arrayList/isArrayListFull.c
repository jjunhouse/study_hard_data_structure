#include "arraylist.h"

int isArrayListFull(ArrayList* pList)
{
    if (pList->maxElementCount == pList->currentElementCount)
        return (TRUE);
    return (FALSE);
}
