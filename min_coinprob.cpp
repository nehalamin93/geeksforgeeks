#include <bits/stdc++.h>

using namespace std;

int function(int arr[],int sum,int n)
{
	int i,j;
	long long int table[sum+1][n+1];
	for(i=0;i<=n;i++)
	{
		table[0][i] = 0;
	}
	for(i=1;i<=sum;i++)
	{
		table[i][0] = INT_MAX;
	}
	for(i=1;i<=sum;i++)
	{
		for(j=1;j<=n;j++)
		{
			long long int b = 0;
			if(i-arr[j]>=0)  b = table[i-arr[j]][j];
			table[i][j] = min(table[i][j-1],1+b);
		}
	}
	return table[sum][n];
}

int main()
{
	int n,i,j,sum;
	cout<<"Enter n:\n";
	cin>>n;
	int arr[n+1];
	cout<<"Enter arr:\n";
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter sum:\n";
	cin>>sum;
	cout<<function(arr,sum,n)<<'\n';
	return 0;
}