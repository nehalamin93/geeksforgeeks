#include <bits/stdc++.h>

using namespace std;

bool findunassign(int grid[][9],int &row,int &col)
{
	for(row=0;row<9;row++)
		for(col=0;col<9;col++)
			if(grid[row][col]==0) return true;
	return false;
}

bool saferow(int grid[][9],int row,int col,int index)
{
	for(int i=0;i<9;i++)
	{
		if(grid[row][i]==index) return false;
	}
	return true;
}

bool safecol(int grid[][9],int row,int col,int index)
{
	for(int i=0;i<9;i++)
	{
		if(grid[i][col]==index) return false;
	}
	return true;
}

bool safegrid(int grid[][9],int row,int col,int index)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i+row][j+col]==index) return false;
		}
	}
	return true;
}

bool issafe(int grid[][9],int row,int col,int index)
{
	return (saferow(grid,row,col,index) && safecol(grid,row,col,index) && safegrid(grid,row-row%3,col-col%3,index));
}

bool SolveSudoku(int grid[][9])
{
	int col,row;
	if(!findunassign(grid,row,col)) return true;
	for(int i = 1;i<=9;i++)
	{
		if(issafe(grid,row,col,i))
		{
			grid[row][col] = i;
			if(SolveSudoku(grid))
				return true;
			else grid[row][col] = 0;
		}
	}
	return false;
}

void printGrid(int grid[][9])
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("%d ", grid[row][col]);
        printf("\n");
    }
}
 
int main()
{
    int grid[9][9] = {{0, 0, 3, 0, 0, 0, 0, 1, 9},
                      {9, 5, 0, 0, 0, 6, 4, 0, 8},
                      {4, 7, 0, 2, 0, 0, 0, 0, 6},
                      {0, 0, 5, 0, 0, 1, 0, 9, 0},
                      {3, 4, 2, 0, 0, 0, 1, 8, 5},
                      {0, 9, 0, 5, 0, 0, 3, 0, 0},
                      {2, 0, 0, 0, 0, 8, 0, 5, 3},
                      {7, 0, 9, 1, 0, 0, 0, 4, 2},
                      {5, 3, 0, 0, 0, 0, 8, 0, 0}};
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         printf("No solution exists");
 
    return 0;
}