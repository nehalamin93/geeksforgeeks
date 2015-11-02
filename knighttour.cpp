#include <bits/stdc++.h>


using namespace std;
#define N 8

void printing(int arr[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
}

bool check(int arr[][N],int x1,int x2)
{
	//cout<<"*";
	if(x1>=0 && x1<8 && x2>=0 && x2<8 && arr[x1][x2]==-1)
		return true;
	else return false;
}

bool function(int arr[][N],int xpath[],int ypath[],int x,int y,int index)
{
	if(index == 64) return true;
	for(int k=0;k<N;k++)
	{
		int x1 = x + xpath[k];
		int y1 = y + ypath[k];
		//cout<<x1<<'-'<<y1<<' ';
		if(check(arr,x1,y1)==true)
		{
			arr[x1][y1] = index;
			if(function(arr,xpath,ypath,x1,y1,index+1)==true)
				{

					return true;
				}
			else 
				arr[x1][y1] = -1;
		}
	}
	return false;
}
void solvekt()
{
	int arr[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			arr[i][j]=-1;
	//int path[][N] = {{1,2},{-1,2},{2,1},{-2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}};
	int xpath[N] = {2,1,-1,-2,-2,-1,1,2};
	int ypath[N] = {1,2,2,1,-1,-2,-2,-1};
	arr[0][0] = 0;
	int index = 1;
	if(function(arr,xpath,ypath,0,0,index)==false) cout<<"NOT POSSIBLE"<<'\n';
	else
	{
		cout<<"POSSIBLE"<<'\n';
		printing(arr);
	}
}


int main()
{
	solvekt();
	return 0;
}