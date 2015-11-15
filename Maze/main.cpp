#include "ArrayHelper.h"
#include "MazeWalker.h"
#include "MazeReader.h"
#include "Test.h"

void mmmmaze(std::string fileToRead, Search search);

int main(int argc, char** argv)
{

	if(argc == 3)
	{
		std::string option = argv[1];
		std::string file = argv[2];
		
		
		
		try
		{
			if(option != "-bfs" && option != "-dfs")
				throw 1;
			else
			{	
				if(option == "-dfs")
				{
					Search s = Search::DFS;
					mmmmaze(file, s);
				}
				if(option == "-bfs")
				{
					Search s = Search::BFS;
					mmmmaze(file, s);
				}
			}
				
				
		}
		catch(int e)
		{
			std::cout << "search argument not valid";
		}
		
		
		
		
	}
	
	if(argc == 2)
	{
		std::string option = argv[1];
	
		if(option == "-test")
		{
			Test mytest;
			mytest.runTests();
		}
	}
	
	if(argc < 2 || argc > 3)
		std::cout << "Please enter valid command line argements";



	return 0;
} 

void mmmmaze(std::string fileToRead, Search search)
{
	try
	{	

		MazeReader mr = MazeReader(fileToRead);
		MazeWalker mw = MazeWalker(mr.getMaze(), mr.getStartCol(), mr.getStartRow(), mr.getCols(), mr.getRows(), search);
		mw.walkMaze();
		ArrayHelper<int>::print2DArray(mw.getVisited(), mw.getVisitedRows(), mw.getVisitedCols(), "\t");	
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what();
	}
}

