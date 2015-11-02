#include <bits/stdc++.h>

using namespace std;

void printing(int arr[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
}
bool function(int arr[][4],int i,int j)
{
	if(i==3 && j==3)
	{
		arr[i][j] = 2;
		return true;
	}
	else
	{
		i++;
		if(arr[i][j]==1 && i<4)
		{
			arr[i][j] = 2;
			if(function(arr,i,j)) return true;
		}
		else
		{
			arr[i][j] = 1;
		}
		i--;
		j++;
		if(arr[i][j]==1 && j<4)
		{
			arr[i][j] = 2;
			if(function(arr,i,j)) return true;
		}
		else 
		{
			arr[i][j] = 1;
		}
		j--;
	}
	return false;
}
int main()
{
	int arr[4][4] = { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 0}
    };
    arr[0][0] = 2;
    if(function(arr,0,0))
    {
    	printing(arr);
    }
    else
    {
    	cout<<"NOT POSSIBLE"<<'\n';
    }
	return 0;
}