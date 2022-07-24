#ifndef _MAP_DEF_
#define _MAP_DEF_
#include <stdio.h>

#define WIDTH 8
#define HEIGHT 8
#define NUM_DIRECTIONS 4
#define ERROR	-1
#define START	-10
#define	END		10

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 0 (위)
	{1, 0},			// 1 (우)
	{0, 1},			// 2 (아래)
	{-1, 0}			// 3 (좌)
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

typedef struct MapPositionType
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// ���� ��ġ�� �̵� ����.
} MapPosition;

#endif