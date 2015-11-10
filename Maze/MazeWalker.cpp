#include "MazeWalker.h"

MazeWalker MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice);
{
	
}

MazeWalker MazeWalker::~MazeWalker()
{
	
}

bool MazeWalker::walkMaze()
{
}

const int* const* MazeWalker::getVisited() const
{
}

int MazeWalker::getVisitedRows() const
{
}

int MazeWalker::getVisitedCols() const
{
}

const char* const* MazeWalker::getMaze() const
{
}

//protected
void MazeWalker::storeValidMoves();
{
}

void MazeWalker::move(Position& p);
{
}

bool MazeWalker::isGoalReached() const;
{
}

