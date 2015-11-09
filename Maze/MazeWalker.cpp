#include "MazeWalker.h"

MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice);
{
}

~MazeWalker()
{
}

bool walkMaze()
{
}

const int* const* getVisited() const
{
}

int getVisitedRows() const
{
}

int getVisitedCols() const
{
}

const char* const* getMaze() const
{
}

//protected
void storeValidMoves();
{
}

void move(Position& p);
{
}

bool isGoalReached() const;
{
}

