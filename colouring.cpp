#include <bits/stdc++.h>

using namespace std;

void printing(vector<int> v)
{
	for(int i=0;i<4;i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}

bool check(bool graph[][4],vector<int> v,int a,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	{
		if(graph[i][col] && v[i] == a)
			return false;
	}
	return true;
}

bool function(bool graph[][4],vector<int>& v,int col,int m)
{
	if(col>=4) return true;
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(check(graph,v,i,col))
			{
				v[col] = i;
				if(function(graph,v,col+1,m))
				{
					return true;
				}
				else
					v[col] = 0; 
			}
		}
		return false;
	}
}

int main()
{
	int i,j,n;
	bool graph[4][4] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    vector<int> v(4);
    if(function(graph,v,0,3))
    {
    	printing(v);
    }
    else
    {
    	cout<<"NOT POSSIBLE\n";
    }
	return 0;
}
