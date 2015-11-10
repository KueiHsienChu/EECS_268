#ifndef MazeReader_H
#define	MazeReader_H

#include "MazeCreationException.h"
#include <fstream>

class MazeReader
{
	public:
		/**
		*       @post A MazeReader is created. A 2D char array is allocated with the maze information.
		*       @throws MazeCreationExecption
		*
		*/
		MazeReader(std::string file) throw (MazeCreationException);

		/**
		*       @post The maze is deallocated.
		*/
		~MazeReader();

		/**
		*       @pre the file was formatting and read in correctly
		*       @return Returns pointer to the maze
		*/
		const char* const* getMaze() const;

		/**
		*       @pre the file was formatted and read in correctly
		*       @returns the number of columns listed in the file
		*/
		int getCols() const;

		/**
		*       @pre the file was formatted and read in correctly
		*       @returns the number of rows listed in the file
		*/
		int getRows() const;

		/**
		*       @pre the file was formatted and read in correctly
		*       @returns the starting column
		*/
		int getStartCol() const;

		/**
		*       @pre the file was formatted and read in correctly
		*       @returns the starting row
		*/
		int getStartRow() const;

        protected:
		/**
		*       @pre the file is properly formatted
		*       @post the characters representing the maze are stores
		*/
		void readMaze() throw (MazeCreationException);  
		
	private:
		
		char** m_maze;
		int col_n = 0;
		int row_n = 0;
		int start_col = 0;
		int start_row = 0;

};

#endif
