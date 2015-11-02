#include <bits/stdc++.h>

using namespace std;

void printing(vector<int> v)
{
	for(int i=0;i<6;i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}

bool check(bool graph[][5],vector<int>& v,int col,int i,map<int,int> hmap)
{
	if(hmap.find(i)!=hmap.end() || graph[i][col]==0)
	{
		//cout<<'*'<<i<<'*';
		return false;
	}
	return true;
}

bool function(bool graph[][5],vector<int>& v,int col,map<int,int>& hmap)
{
	int n = 5;
	if(col==n)
	{
		if(graph[v[0]][v[n-1]]==1)
		{
			v[n] = 0;
			return true;
		}
		else
			return false;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(check(graph,v,v[col-1],i,hmap))
			{	
				v[col] = i;
				hmap[i]=i;
				//cout<<i<<' ';
				if(function(graph,v,col+1,hmap))
				{
					//cout<<i<<'\n';
					return true;
				}
				else
				{
					hmap.erase(i);
					v[col] = 0;
				}
			}
		}
		return false;
	}
}

int main()
{
	int i,j,n;
	bool graph[5][5] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
    /*bool graph[5][5] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };*/
    vector<int> v(6);
    map<int,int> hmap;
    v[0] = 0;
    hmap[0] = 0;
    if(function(graph,v,1,hmap))
    {
    	printing(v);
    }
    else 
    	cout<<"NOT POSSIBLE\n";

	return 0;
}