//============================================================================
// Name        : pacman-astar.cpp
// Author      : Raghavendran N
// Version     :
// Copyright   : Your copyright notice
// Description : Solution for
//============================================================================

#include <stdio.h>

const int MAX_ROWS = 101;
const int MAX_COLS = 101;

char pacmanMatrix[MAX_ROWS][MAX_COLS];
int visited[MAX_ROWS][MAX_COLS];
int costs[MAX_ROWS][MAX_COLS];

struct Cell {
	int X;
	int Y;
};

void ReadPacmanMatrix(int nRows, int nCols)
{
	char newlineChar = '\n';
	scanf("%c", &newlineChar); // Got to read this char before reading the matrix!

	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nCols; ++j) {
			scanf("%c", &pacmanMatrix[i][j]);
		}
		scanf("%c", &newlineChar);
	}
}

void PrintMatrix(int nRows, int nCols)
{
	for (int i = 0; i < nRows; ++i) {
		printf("%2d: ", (i + 1));
		for (int j = 0; j < nCols; ++j) {
			printf("%c", pacmanMatrix[i][j]);
		}
		printf("\n");
	}
}

int GetCost(int x, int y, int goalX, int goalY, int maxX, int maxY)
{
	if (x < 0 || x >= maxX)
		return -1;
	if (y < 0 || y >= maxY)
		return -1;
	if (pacmanMatrix[x][y] == '%')
		return -1;
	if (pacmanMatrix[x][y] == '-') { // Manhattan distance
		return 1 + ((goalX > x) ? (goalX - x) : (x - goalX)) + ((goalY > y) ? (goalY - y) : (y - goalY));
	}
	if (pacmanMatrix[x][y] == '.')
		return 0;
	if (pacmanMatrix[x][y] == 'P')
		return 0;

	return -1;
}

void SetCosts(int goalX, int goalY, int maxX, int maxY)
{
	for (int i = 0; i < maxX; ++i) {
		for (int j = 0; j < maxY; ++j) {
			costs[i][j] = GetCost(i, j, goalX, goalY, maxX, maxY);
		}
	}
}

int main() {
	int pacmanX = 0, pacmanY = 0;
	scanf("%d %d", &pacmanX, &pacmanY);

	int foodX = 0, foodY = 0;
	scanf("%d %d", &foodX, &foodY);

	int nRows = 0, nCols = 0;
	scanf("%d %d", &nRows, &nCols);

	ReadPacmanMatrix(nRows, nCols);

	SetCosts(foodX, foodY, nRows, nCols);

	int curX = pacmanX, curY = pacmanY;
	int leastCostCellX = 0, leastCostCellY = 0;
	int cost = 0, leastCost = 0;

	visited[curX][curY] = 1;
	costs[curX][curY] = 0;

	Cell leftCell, rightCell, topCell, botCell, leastCostlyCell;
	Cell cells[4];

	while(curX != foodX && curY != foodY) {
		leftCell.X  = curX - 1, leftCell.Y  = curY;
		topCell.X   = curX, 	topCell.Y	= curY - 1;
		rightCell.X = curX + 1, rightCell.Y = curY;
		botCell.X   = curX, 	botCell.Y   = curY + 1;

		cells[0] = leftCell;
		cells[1] = topCell;
		cells[2] = rightCell;
		cells[3] = botCell;

		for (int i = 0; i < 4; ++i) {
			if (costs[cells[i].X][cells[i].Y] == 0)
				break; // goal reached
			else {
				if (costs[cells[i].X][cells[i].Y] != -1 &&
						costs[cells[i].X][cells[i].Y] < leastCost)
				{
					leastCost = costs[cells[i].X][cells[i].Y];
					leastCostlyCell = cells[i];
				}
			}
		}

		curX = leastCostlyCell.X;
		curY = leastCostlyCell.Y;
	}

	return 0;
}
