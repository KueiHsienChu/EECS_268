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
	
	//matrix that record visited little paths (blocks)
	m_visited = new int*[rows];
	for(int i = 0; i < rows; i++)
		m_visited[i] = new int[cols];

	//
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			m_visited[i][j] = 0;

	//mark starting position			
	m_visited[startRow][startCol] = m_curStep;
	


		
}

MazeWalker::~MazeWalker()
{
	m_maze = nullptr;
	delete m_visited;
	m_visited = nullptr;
}

bool MazeWalker::walkMaze()
{
	 
	/*
	set up position; 
	beware that value may exceed or less than the m_rows and m_cols, 
	so we need to set conditions to check
	*/
	

	if(m_searchType == Search::DFS)
	{
		if(isGoalReached())
		{
			while(m_moveStack.size() > 0)
				m_moveStack.pop();
			return true;
		}
		else
		{
			//direction_ is the character at the specific location w.r.t the m_curPos to the maze 
			char up_ = m_maze[ m_curPos.getRow()-1 ][ m_curPos.getCol() ];
			char right_ = m_maze[ m_curPos.getRow() ][ m_curPos.getCol()+1 ];
			char down_ = m_maze[ m_curPos.getRow()+1 ][ m_curPos.getCol() ];
			char left_ = m_maze[ m_curPos.getRow() ][ m_curPos.getCol()-1 ];
			//positions ---- use to check if they exceeds the boundary of the maze
			int up_move = m_curPos.getRow()-1;
			int right_move = m_curPos.getCol()+1;
			int down_move = m_curPos.getRow()+1;
			int left_move = m_curPos.getCol()-1;

			if((up_ == 'P' || up_ == 'E') && up_move >= 0) //so it's within range
			{
				Position up = Position( m_curPos.getRow()-1 , m_curPos.getCol() );
				m_moveStack.push(up);
			}
			
			if((right_ == 'P' || right_ == 'E') && right_move < m_cols) //so it's within range
			{
				Position right = Position( m_curPos.getRow() , m_curPos.getCol()+1 );
				m_moveStack.push(right);
			}
		
			if((down_ == 'P' || down_ == 'E') && down_move < m_rows)  //so it's within range
			{
				Position down = Position( m_curPos.getRow()+1 , m_curPos.getCol() );
				m_moveStack.push(down);
			}
		
			if((left_ == 'P' || left_ == 'E') && left_move >= 0 )  //so it's within range
			{
				Position left = Position( m_curPos.getRow() , m_curPos.getCol()-1 );
				m_moveStack.push(left);
			}

			while(m_moveStack.size() > 0)
			{	
				Position temp = Position(m_moveStack.top().getRow(), m_moveStack.top().getCol());
				m_moveStack.pop(); //pop
				if( m_visited[ temp.getRow() ][ temp.getCol() ] == 0 )
				{	move(temp); //move to that temporary position
					storeValidMoves(); //mark as visited
					walkMaze();
				}
				
			}
		}//end else
			
	}//end if DFS	
	return false;
	
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
		//step increment
		m_curStep++; 
		m_visited[ m_curPos.getRow() ][ m_curPos.getCol() ] = m_curStep;
	}
	else if(m_searchType == Search::BFS)
	{
		//step increment
		m_curStep++; 
		m_visited[ m_curPos.getRow() ][ m_curPos.getCol() ] = m_curStep;
	}
	
}

void MazeWalker::move(Position& p)
{
	//move 
	m_curPos = Position( p.getRow(), p.getCol() );
	
}

bool MazeWalker::isGoalReached() const
{
	char bang = m_maze[m_curPos.getRow()][m_curPos.getCol()];
	
	if(bang != 'E')
		return false;
	else
		return true;
}














