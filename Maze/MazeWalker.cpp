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
	


}

MazeWalker::~MazeWalker()
{
	
}

bool MazeWalker::walkMaze()
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
		storeValidMoves();
		
		if(isGoalReached())
		{
			return true;
		}
		else
		{
			//up
			if(up.getRow() >= 0) //so it's within range
			{
				if(m_maze[ up.getRow() ][ up.getCol() ] != 'W')
				{
					move(up);
					walkMaze();
				}
			}		
			//right
			if(right.getCol() < m_cols) //so it's within range
			{
				if(m_maze[ right.getRow() ][ right.getCol() ] != 'W')
				{
					move(right);
					walkMaze();
				}
			}
			//down
			if(down.getRow() < m_rows)  //so it's within range
			{
				if(m_maze[ down.getRow() ][ down.getCol() ] != 'W')
				{
					move(down);
					walkMaze();
				}
			}
			//left
			if(left.getRow() >= 0)  //so it's within range
			{
				if(m_maze[ left.getRow() ][ left.getCol() ] != 'W')
				{
					move(down);
					walkMaze();
				}
			}
				
		}
		m_moveStack.pop();
		return false;
	}//end DFS
	
	/*
		else if(m_searchType == Search::BFS)
		{
			int vd = 0; //valid directions
			
			//up
			if(up.getRow() >= 0) //so it's within range
			{
				if(m_maze[ up.getRow() ][ up.getCol() ] != 'W')
				{
					move(up);
					storeValidMoves(); 
					vd++;
					if(isGoalReached())
						return true;
				}
			}		
			//right
			if(right.getCol() < m_cols) //so it's within range
			{
				if(m_maze[ right.getRow() ][ right.getCol() ] != 'W')
				{
					move(right);
					storeValidMoves(); 
					vd++;
				}
			}
			//down
			if(down.getRow() < m_rows)  //so it's within range
			{
				if(m_maze[ down.getRow() ][ down.getCol() ] != 'W')
				{
					move(down);
					storeValidMoves(); 
					vd++;
				}
			}
			//left
			if(left.getRow() >= 0)  //so it's within range
			{
				if(m_maze[ left.getRow() ][ left.getCol() ] != 'W')
				{
					move(down);
					storeValidMoves(); 
					vd++;
				}
			}
			
			//don't forget m_curPos is at down; and m_curStep is ... think about process
			
			bool varify = false; //flag for varification
			
			for(int i = 0; i < vd; i++)
			{
				m_curPos = m_moveQueue.front();
				if(m_maze[ m_curPos.getRow() ][ m_curPos.getCol() ] == 'P')
				{
					verify = false;
					m_moveQueue.pop();
					m_moveQueue.push(m_curPos);
				}
				else
					verify = true; //it's not 'p' then it must be 'E'
			}
			
			if(verify == true)	
				return true;
			else
			{
				for(int i = 0; i < vd; i++)
				{
					m_curPos = m_moveQueue.front();
					walkMaze();
					m_moveQueue.pop();
					m_moveQueue.push(m_curPos);
				}
			}
			
		}//end else if
		
	}//end else	
	
	*/
}

const int* const* MazeWalker::getVisited() const
{
		return(m_visited);
}

int MazeWalker::getVisitedRows() const
{
	return(m_rows);
}

int MazeWalker::getVisitedCols() const
{
	return(m_cols);
}

const char* const* MazeWalker::getMaze() const
{
	return(m_maze);
}

//protected
void MazeWalker::storeValidMoves()
{	
	if(m_searchType == Search::DFS)
	{
		m_moveStack.push(m_curPos); //store position
	}
	else if(m_searchType == Search::BFS)
	{
		m_moveQueue.push(m_curPos); //store position
	}
	
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

