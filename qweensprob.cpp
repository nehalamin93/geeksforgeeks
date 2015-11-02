#include <bits/stdc++.h>

using namespace std;

void printing(vector< vector<int> > v)
{
	int n = v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<' ';
		}
		cout<<'\n';
	}
}

bool check(vector< vector<int> > v,int row,int col)
{
	int n = v.size();
	int i,j;
	for(i=0;i<col;i++)
	{
		if(v[row][i]) return false;
	}
	for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
	{
		if(v[i][j]) return false;
	}
	for(i=row+1,j=col-1;i<n && j>=0;i++,j--)
	{
		if(v[i][j]) return false;
	}
	return true;
}

bool function(vector< vector<int> >& v,int col)
{
	int n = v.size();
	if(col>=n) return true;
	else
	{
		for(int i=0;i<n;i++)
		{
			if(check(v,i,col))
			{
				v[i][col] = 1;
				if(function(v,col+1))
				{
					return true;
				}
				else 
					v[i][col] = 0;
			}
		}
		return false;
	}
}

int main()
{
	int n;
	cin>>n;
	vector< vector<int> > arr(n,vector<int>(n));
	if(function(arr,0))
	{
		printing(arr);
		cout<<'\n';
	}
	else
		cout<<"NOT POSSIBLE"<<'\n';
	return 0;
}