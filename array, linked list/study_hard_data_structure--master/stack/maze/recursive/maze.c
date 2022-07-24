#include "mapdef.h"
#include "linkedstack.h"

MapPosition    findStartingPosition(int maze[HEIGHT][WIDTH])
{
    int i;
    int j;
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
            pos.x = i;
            pos.y = j;
            if (maze[j][i] == START)
                return (pos);
            j++;
        }
        i++;
    }
    pos.direction = -1;
    return (pos);
}

int findPath(int maze[HEIGHT][WIDTH], MapPosition pos, LinkedStack *pStack)
{
    MapPosition nextPos;
    int nextX;
    int nextY;

    if (!pStack)
        return (ERROR);
    if (pos.x < 0 || pos.y < 0 || pos.x >= WIDTH || pos.y >= HEIGHT)
        return (FALSE);
    else if (maze[pos.y][pos.x] == WALL || maze[pos.y][pos.x] == VISIT)
        return (FALSE);
    else if (maze[pos.y][pos.x] == END)
    {
        pushLS(pStack, pos);
        return (TRUE);
    }
	else
    {
        pushLS(pStack, pos);
        maze[pos.y][pos.x] = VISIT; // 현재 위치를 2로 변경
        while (pos.direction < NUM_DIRECTIONS)
        {
            // 다음 좌표 설정
            nextX = pos.x + DIRECTION_OFFSETS[pos.direction][0];
            nextY = pos.y + DIRECTION_OFFSETS[pos.direction][1];
            nextPos.x = nextX;
            nextPos.y = nextY;
            nextPos.direction = 0;
            if (findPath(maze, nextPos, pStack))
                return (TRUE);
            pos.direction += 1;
        }
        // 길을 찾지 못하면 스택에서 현재 위치 제거
        popLS(pStack);
        return (FALSE);
    }
}

void	displayPath(LinkedStack *pStack)
{
    StackNode   *pop;

	if (!isLinkedStackEmpty(pStack))
    {
        while (!isLinkedStackEmpty(pStack))
        {
            pop = popLS(pStack);
            printf("(%d, %d)\n", pop->pos.x, pop->pos.y);
        }
    }
    else
        printf("미로를 빠져나갈 길을 찾지 못했습니다.");
}

int main(void)
{
    LinkedStack *pStack;
    MapPosition pos;
    int         isFound;
    int         maze[HEIGHT][WIDTH] = 
    {
        {START, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, END}
    };
    pStack = createLinkedStack();
    pos = findStartingPosition(maze);
    if (pos.direction == -1)
    {
        printf("Error occurs because there is no start.\n");
        return (ERROR);
    }
    isFound = findPath(maze, pos, pStack);
    if (isFound)
        displayPath(pStack);
    return (0);
}