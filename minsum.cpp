#include <bits/stdc++.h>

using namespace std;

int min(int a,int b)
{
	if(a>b) return b;
	return a;
}

int minCost(int arr[][3],int i,int j,int m,int n)
{
	if(i==m && j==n)
	{
		return arr[i][j];
	}
	else if(i==m)
	{
		return arr[i][j]+minCost(arr,i,j+1,m,n);
	}
	else if(j==n)
	{
		return arr[i][j]+minCost(arr,i+1,j,m,n);
	}
	else
	{
		return arr[i][j]+min(minCost(arr,i+1,j,m,n),min(minCost(arr,i,j+1,m,n),minCost(arr,i+1,j+1,m,n)));
	}
}

int main()
{
	int cost[3][3] = { {1, 2, 3},
	                    {4, 8, 2},
	                    {1, 5, 3} };
   	printf(" %d ", minCost(cost,0,0,2, 2));
	return 0;
}