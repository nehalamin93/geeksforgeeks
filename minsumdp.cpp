#include <bits/stdc++.h>

using namespace std;

int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
int minCost(int cost[][3],int m,int n)
{
	int i,j,l,k;
	int **arr;
	arr = (int **)malloc(4*sizeof(int *));
	for(i=0;i<4;i++) arr[i]= (int *)malloc(4*sizeof(int));
	for(i=0;i<4;i++) arr[i][0] = INT_MAX;
	for(j=0;j<4;j++) arr[0][j] = INT_MAX;
	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++)
		{
			if(i==1 && j==1)
			{
				arr[i][j] = cost[0][0];
			}
			else
			{
				arr[i][j] = cost[i-1][j-1];
				arr[i][j] += min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1])); 
				//cout<<arr[i][j]<<'\n';
			}
		}
	}
	for(i=1;i<4;i++)
	{
		for(j=1;j<4;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
	return arr[m+1][n+1];
}

int main()
{
	int cost[3][3] = { {1, 2, 3},
	                    {4, 8, 2},
	                    {1, 5, 3} };
   	printf(" %d \n", minCost(cost,2, 2));

	return 0;
}