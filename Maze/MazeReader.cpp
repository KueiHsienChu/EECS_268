#include "MazeReader.h"

MazeReader MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
	std::ifstream read(file);
	
	if(file.good())
	{
	}
	else
		throw(MazeCreationException("No such file exist in your folder");
	
	
	read >> row_n;
	read >> col_n;
	read >> start_row;
	read >> start_col;	
	
	
}

MazeReader MazeReader::~MazeReader()
{
}

/**
*       @pre the file was formatting and read in correctly
*       @return Returns pointer to the maze
*/
const char* const* MazeReader::getMaze() const
{
	
}

int MazeReader::getCols() const
{
	return(col_n);
}

int MazeReader::getRows() const
{
	return(row_n);
}

int MazeReader::getStartCol() const
{
	return(start_col);
}

int MazeReader::getStartRow() const
{
	return(start_row);
}

//protected

/**
*       @pre the file is properly formatted
*       @post the characters representing the maze are stores
*/
void MazeReader::readMaze() throw (MazeCreationException);  
{
	if(col_n > 0 && row_n > 0 && start_row > 0 && start_col > 0)
	{
			
		m_maze = new int*[row_n];
		for(int i = 0; i < row_n; i++)
			m_maze[i] = new int*[col_n];
			
		for(int d = 0; d < row_n; d++)
			for(int g = 0; g < col_n; g++)
				
	}
	else
		throw(MazeCreationException("Maze no good");

}

