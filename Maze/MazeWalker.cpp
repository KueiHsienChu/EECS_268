#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice)
{
	m_searchType = searchChoice;

	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;

	m_curPos = Position(startRow, startCol);
	m_startPos = Position(startRow, startCol);
}

MazeWalker::~MazeWalker()
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
void MazeWalker::storeValidMoves()
{
}

void MazeWalker::move(Position& p)
{
}

bool MazeWalker::isGoalReached() const
{
}

