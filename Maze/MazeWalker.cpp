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
	
	char up_ = 'n'; char right_ = 'n'; char down_ = 'n'; char left_ = 'n';
	
	//direction_ is the character at the specific location w.r.t the m_curPos to the maze 
	//So the first time this method is called, it's at the start position
	if(m_curPos.getRow()-1 >= 0)
		up_ = m_maze[ m_curPos.getRow()-1 ][ m_curPos.getCol() ];
	if(m_curPos.getCol()+1 < m_cols)
		right_ = m_maze[ m_curPos.getRow() ][ m_curPos.getCol()+1 ];
	if(m_curPos.getRow()+1 < m_rows)
		down_ = m_maze[ m_curPos.getRow()+1 ][ m_curPos.getCol() ];
	if(m_curPos.getCol()-1 >= 0)
		left_ = m_maze[ m_curPos.getRow() ][ m_curPos.getCol()-1 ];
		
	//positions ---- use to check if they exceeds the boundary of the maze
	int up_move = m_curPos.getRow()-1;
	int right_move = m_curPos.getCol()+1;
	int down_move = m_curPos.getRow()+1;
	int left_move = m_curPos.getCol()-1;


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
				
			}//endwhile
		}//end else	
	}//end if DFS	
	
	
	/*Breadth-First-Search( Maze m )
	EnQueue( m.StartNode )
	While Queue.NotEmpty 
		c <- DeQueue
		If c is the goal
		    Exit
		Else
		    Foreach neighbor n of c
			If n "Unvisited"
			    Mark n "Visited"                    
			    EnQueue( n )
		    Mark c "Examined"                    
	End procedure
	*/

	if(m_searchType == Search::BFS)
	{
		int step = 1;
		std::cout << "OH YEAH 1 !!!!!!!!!!!!!!\n";
		m_moveQueue.push(m_curPos);//EnQueue( m.StartNode )
			
		while(m_moveQueue.size() > 0 && !isGoalReached())
		{
			
			std::cout << "OH YEAH 2 !!!!!!!!!!!!!!\n";
			
			m_curPos = Position(m_moveQueue.front().getRow(), m_moveQueue.front().getCol());
			std::cout << "Position (" << m_curPos.getRow() << ", " << m_curPos.getCol() << ")\n";
			
			//store valid moves after first run
			if(m_curPos.getRow() != m_startPos.getRow() && m_curPos.getCol() != m_startPos.getCol())
				storeValidMoves();
				
			if(m_curPos.getRow()-1 >= 0)
				up_ = m_maze[ m_curPos.getRow()-1 ][ m_curPos.getCol() ];
			else
				up_ = 'n';
			if(m_curPos.getCol()+1 < m_cols)
				right_ = m_maze[ m_curPos.getRow() ][ m_curPos.getCol()+1 ];
			else
				right_ = 'n';
			if(m_curPos.getRow()+1 < m_rows)
				down_ = m_maze[ m_curPos.getRow()+1 ][ m_curPos.getCol() ];
			else
				down_ = 'n';
			if(m_curPos.getCol()-1 >= 0)
				left_ = m_maze[ m_curPos.getRow() ][ m_curPos.getCol()-1 ];
			else
				left_ = 'n';
			
			int up_move = m_curPos.getRow()-1;
			int right_move = m_curPos.getCol()+1;
			int down_move = m_curPos.getRow()+1;
			int left_move = m_curPos.getCol()-1;
			
			m_moveQueue.pop();
			
			if(isGoalReached())
			{
				while(m_moveQueue.size() > 0)
				{
					m_moveQueue.pop();
					std::cout << "Goal reached!!!" << "m_moveQueue size: " << m_moveQueue.size() << "\n";
				}
				return true;
			}	
			else
			{	
				std::cout << "OH YEAH 3 !!!!!!!!!!!!!!\n";
				//first, we need to store all valid neighbors into the queue
				//for each neighbor: up - right - down - left
				if((up_ == 'P' || up_ == 'E') && up_move >= 0) //so it's within range
				{
					std::cout << "OH YEAH up !!!!!!!!!!!!!!\n";
					step++;
					std::cout << "step: " << step << "\n";
					//create a position
					std::cout << "OH YEAH up 1 !!!!!!!!!!!!!!\n";
					Position up = Position( m_curPos.getRow()-1 , m_curPos.getCol() );
					//push to quene
					if( m_visited[ up.getRow() ][ up.getCol() ] == 0 )
						m_moveQueue.push(up);
				}
			
				if((right_ == 'P' || right_ == 'E') && right_move < m_cols) //so it's within range
				{
					std::cout << "OH YEAH right !!!!!!!!!!!!!!\n";
					step++;
					std::cout << "step: " << step << "\n";
					Position right = Position( m_curPos.getRow() , m_curPos.getCol()+1 );
					if( m_visited[ right.getRow() ][ right.getCol() ] == 0 )
						m_moveQueue.push(right);
				}
		
				if((down_ == 'P' || down_ == 'E') && down_move < m_rows)  //so it's within range
				{
					std::cout << "OH YEAH down !!!!!!!!!!!!!!\n";
					step++;
					std::cout << "step: " << step << "\n";
					Position down = Position( m_curPos.getRow()+1 , m_curPos.getCol() );
					if( m_visited[ down.getRow() ][ down.getCol() ] == 0 )
						m_moveQueue.push(down);
				}
		
				if((left_ == 'P' || left_ == 'E') && left_move >= 0 )  //so it's within range
				{
					std::cout << "OH YEAH left !!!!!!!!!!!!!!\n";
					step++;
					std::cout << "step: " << step << "\n";
					Position left = Position( m_curPos.getRow() , m_curPos.getCol()-1 );
					if( m_visited[ left.getRow() ][ left.getCol() ] == 0 )
						m_moveQueue.push(left);			
				}
				
					std::cout << "OH YEAH 4 !!!!!!!!!!!!!!\n";
				
			}//end else
			
			std::cout << "Queue size: " << m_moveQueue.size() << "\n";
		}//end while
			
	}
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














