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
	std::cout << "Position ( " << m_curPos.getRow() << ", " << m_curPos.getCol() << " )";
	
	if(m_searchType == Search::DFS)
	{
		std::cout << "OH YEAH 1 !!!!!\n";
		
		int vm = 0; //valid move

		Position up = Position( m_curPos.getRow()-1 , m_curPos.getCol() );
		if(m_maze[ up.getRow() ][ up.getCol() ] == 'P') //so it's within range
		{
			m_moveStack.push(up);
			vm++;
		}
	
		Position right = Position( m_curPos.getRow() , m_curPos.getCol()+1 );
		if(m_maze[ right.getRow() ][ right.getCol() ] == 'P') //so it's within range
		{
			m_moveStack.push(right);
			vm++;
		}
	
		Position down = Position( m_curPos.getRow()+1 , m_curPos.getCol() );
		if(m_maze[ down.getRow() ][ down.getCol() ] == 'P')  //so it's within range
		{
			m_moveStack.push(down);
			vm++;
		}
		
		Position left = Position( m_curPos.getRow() , m_curPos.getCol()-1 );
		if(m_maze[ left.getRow() ][ left.getCol() ] == 'P')  //so it's within range
		{
			m_moveStack.push(left);
			vm++;
		}
		while(vm > 0)
		{	
			std::cout << "OH YEAH 2 !!!!!\n";
			move(m_moveStack.top()); //move to that position; m_curPos is now at the position of the top stored position of the stack
			std::cout << "OH YEAH 3 !!!!!\n";
			storeValidMoves(); //store the moves
			std::cout << "OH YEAH 4 !!!!!\n";
			m_moveStack.pop(); //pop this in the stack
			//std::cout << "Position ( " << m_curPos.getRow() << ", " << m_curPos.getCol() << " )";
			std::cout << "OH YEAH 5 !!!!!\n";
			if(isGoalReached())
			{
				return true;
			}
			else if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'P')
			{
				std::cout << "OH YEAH 6 !!!!!\n";
				walkMaze();
			}
			std::cout << "OH YEAH 7 !!!!!\n";
			vm--;
		}
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
	if(m_searchType == Search::DFS)
	{
		if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
			return true;
		else
			return false;
	}
}














