#include "mapdef.h"
#include "linkedstack.h"
#include <string.h>

MapPosition    findStartingPosition(char maze[8][9])
{
    int 		i;
    int 		j;
    MapPosition pos;

    i = 0;
    pos.x = 0;
    pos.y = 0;
    pos.direction = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < HEIGHT)
        {
            pos.x = j;
            pos.y = i;
            if (maze[i][j] == 's')
                return (pos);
            j++;
        }
        i++;
    }
    pos.direction = -1;
    return (pos);
}

int findAvailablePath(char c)
{
    if (c == NOT_VISIT)
        return (1);
    else if (c == 'e')
    {
        return (1);
    }
    return (0);
}

LinkedStack *findPath(char maze[8][9], MapPosition pos, LinkedStack *pathStack)
{
    StackNode   element;
    StackNode   *popstat;
    int         x;
    int         y;

    x = pos.x;
    y = pos.y;
    maze[pos.y][pos.x] = NOT_VISIT;
    pos.direction = 0;
    while (1)
    {
        if ((findAvailablePath(maze[pos.y - 1][pos.x]) && pos.y > 0) && pos.direction != 3)
        {
            pos.y -= 1;
            element.data = 'U';
            pushLS(pathStack, element);
            if (maze[pos.y][pos.x] == 'e')
                return (pathStack);
            maze[pos.y][pos.x] = VISIT;
            pos.direction = 1;
        }
        else if ((findAvailablePath(maze[pos.y][pos.x + 1]) && pos.x < 8) && pos.direction != 4)
        {
            pos.x += 1;
            element.data = 'R';
            pushLS(pathStack, element);
            if (maze[pos.y][pos.x] == 'e')
                return (pathStack);
            maze[pos.y][pos.x] = VISIT;
            pos.direction = 2;
        }
        else if ((findAvailablePath(maze[pos.y + 1][pos.x]) && pos.y < 8) && pos.direction != 1)
        {
            pos.y += 1;
            element.data = 'D';
            pushLS(pathStack, element);
            if (maze[pos.y][pos.x] == 'e')
                return (pathStack);
            maze[pos.y][pos.x] = VISIT;
            pos.direction = 3;
        }
        else if ((findAvailablePath(maze[pos.y][pos.x - 1]) && pos.x > 0) && pos.direction != 2)
        {
            pos.x -= 1;
            element.data = 'L';
            pushLS(pathStack, element);
            if (maze[pos.y][pos.x] == 'e')
                return (pathStack);
            maze[pos.y][pos.x] = VISIT;
            pos.direction = 4;
        }
        else
        {
            if (!isLinkedStackEmpty(pathStack))
            {
                popstat = popLS(pathStack);
                if (popstat->data == 'U')
                {
                    pos.y += 1;
                    pos.direction = 3;
                }
                else if (popstat->data == 'R')
                {
                    pos.x -= 1;
                    pos.direction = 4;
                }
                else if (popstat->data == 'D')
                {
                    pos.y -= 1;
                    pos.direction = 1;
                }
                else if (popstat->data == 'L')
                {
                    pos.x += 1;
                    pos.direction = 2;
                }
            }
            else
            {
                printf("not find exit");
                pos.direction = -1;
                return (pathStack);
            }
        }
    }
	return (pathStack);
}

int main(void)
{
    LinkedStack *pStack;
    MapPosition pos;

    char        maze[8][9];
//    {
//       {'s', '0', '1', '1', '1', '1', '1', '1'},
//       {'1', '0', '0', '0', '0', '0', '0', '1'},
//       {'1', '1', '1', '0', '1', '1', '1', '1'},
//       {'1', '1', '1', '0', '1', '1', '1', '1'},
//       {'1', '0', '0', '0', '0', '0', '0', '1'},
//       {'1', '0', '1', '1', '1', '1', '1', '1'},
//       {'1', '0', '0', '0', '0', '0', '0', '1'},
//       {'1', '1', '1', '1', '1', '1', '1', 'e'}
    strcpy(maze[0], "11111111");
    strcpy(maze[1], "11100001");
    strcpy(maze[2], "11101101");
    strcpy(maze[3], "11101101");
    strcpy(maze[4], "1es00001");
    strcpy(maze[5], "11111111");
    strcpy(maze[6], "10000001");
    strcpy(maze[7], "11111111");
//    };
    pStack = createLinkedStack();
    pos = findStartingPosition(maze);
    if (pos.direction == -1)
    {
        printf("Error occurs because there is no start.\n");
        return (ERROR);
    }
    pStack = findPath(maze, pos, pStack);
    displayPath(pStack);
    return (0);
}
