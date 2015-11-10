#include "MazeReader.h"


MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
	std::ifstream read(file);
	
	m_maze = nullptr;
	
	if(read.good())
	{
		read >> row_n;
		read >> col_n;
		read >> start_row;
		read >> start_col;

			if(row_n < 1 || col_n < 1)
				throw(MazeCreationException("Rows or Columns are less than 1"));
			if(start_row >= row_n || start_col >= col_n)
				throw(MazeCreationException("Starting position has the wrong inputs"));
	}
	else
		throw(MazeCreationException("No such file exist in your folder"));
	
	
	m_maze = new char*[row_n];

	for(int i = 0; i < row_n; i++)
		m_maze[i] = new char[col_n];
		
	for(int d = 0; d < row_n; d++)
		for(int g = 0; g < col_n; g++)
			read >> m_maze[d][g];
	read.close();	
	
	
}

MazeReader::~MazeReader()
{
	for(int i = 0; i < row_n; i++)
		delete[] m_maze[i];

	delete [] m_maze;
}

/**
*       @pre the file was formatting and read in correctly
*       @return Returns pointer to the maze
*/
const char* const* MazeReader::getMaze() const
{
	return(m_maze);
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
void MazeReader::readMaze() throw (MazeCreationException)
{
	//not needed

}


