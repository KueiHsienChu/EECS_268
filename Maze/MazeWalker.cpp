#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice)
{
	m_searchType = searchChoice;

	//set up matrix
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;

	//position setup
	m_curPos = Position(startRow, startCol);
	m_startPos = Position(startRow, startCol);
	
	//start position
	m_curStep = 1;
	
	//matrix that record visited little paths
	m_visited = new int*[rows];
	for(int i = 0; i < rows; i++)
		m_visited[i] = new int[cols];
	
	//store the start step

}

MazeWalker::~MazeWalker()
{
	
}

bool MazeWalker::walkMaze()
{
	storeValidMoves(); 	
		
	if(isGoalReached())
	{
	}
	else
	{	
		/*
		set up position; 
		beware that value may exceed or less than the m_rows and m_cols, 
		so we need to set conditions to check
		*/
		Position up = Position( m_curPos.getRow()-1 , m_curPos.getCol() );
		Position right = Position( m_curPos.getRow() , m_curPos.getCol()+1 );
		Position down = Position( m_curPos.getRow()+1 , m_curPos.getCol() );
		Position left = Position( m_curPos.getRow() , m_curPos.getCol()-1 );
	
	
		if(m_searchType == Search::DFS)
		{
			//up
			if(up.getRow() >= 0) //so it's within range
			{
				if(m_maze[ up.getRow() ][ up.getCol() ] == 'P')
				{
					move(up);
				}
			}		
			//right
			if(right.getCol() < m_cols) //so it's within range
			{
				if(m_maze[ right.getRow() ][ right.getCol() ] == 'P')
					move(right);
			}
			//down
			if(down.getRow() < m_rows)  //so it's within range
			{
				if(m_maze[ down.getRow() ][ down.getCol() ] == 'P')
					move(down);
			}
			//left
			if(left.getRow() >= 0)  //so it's within range
			{
				if(m_maze[ left.getRow() ][ left.getCol() ] == 'P')
					move(down);
			}
		}
		else if(m_searchType == Search::BFS)
		{
			//up
			//right
			//down
			//left
		}
		
	}//end else	
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
	return(m_maze);
}

//protected
void MazeWalker::storeValidMoves()
{
	m_visited[ m_curPos.getRow() ][ m_curPos.getCol() ] = m_curStep;
}

void MazeWalker::move(Position& p)
{
	//move 
	m_curPos = Position( p.getRow(), p.getCol() );
	
	//step increment
	m_curStep++; 
}

bool MazeWalker::isGoalReached() const
{
	if(m_maze[ m_curPos.getRow() ][ m_curPos.getCol() ] == 'E')
		return true;
	else
		return false;
}

