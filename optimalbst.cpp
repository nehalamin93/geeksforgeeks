#include <bits/stdc++.h>

using namespace std;

void printing(vector< vector<int> > arr)
{
	cout<<'\n';
	int n = arr.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
}

int optimalSearchTree(int keys[],int freq[],int n)
{
	int i,j,k,l;
	vector< vector<int> > v(n,vector<int>(n));
	vector< vector<int> > f(n,vector<int>(n));
	for(i=0;i<n;i++)
	{
		v[i][i] = freq[i];
	}
	for(i=0;i<n;i++)
	{
		int sum = 0;
		for(j=i;j<n;j++)
		{
			sum += freq[j];
			f[i][j] = sum;
		}
	}
	//printing(f);
	for(k=1;k<n;k++)
	{
		for(i=0;i<n-k;i++)
		{
			j = i+k;
			v[i][j] = f[i][j];
			int min = INT_MAX;
			for(l=i;l<=j;l++)
			{
				int a,b;
				if(l-1<0) a = 0;
				else a = v[i][l-1];
				if(l+1>=n) b = 0;
				else b = v[l+1][j];
				if(min>a+b) min = a+b;
			}
			v[i][j]+=min;
		}
	}
	printing(v);
	return v[0][n-1];
}

int main()
{
	int i,j,k,l;
	int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));
	return 0;
}