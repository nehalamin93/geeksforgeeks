#include <bits/stdc++.h>

using namespace std;

void dfs(int i,vector<int> &visited,stack<int> &sta,vector< vector<int> > v)
{
	visited[i] = 1;
	int j;
	for(j=0;j<v[i].size();j++)
	{
		if(visited[v[i][j]]==0)
		{
			dfs(v[i][j],visited,sta,v);
		}
	}
	sta.push(i);
}

int main()
{
	int i,j,m,n,s;
	cout<<"Enter no of vetices:\n";
	cin>>n;
	cout<<"Enter no. of edges:\n";
	cin>>m;
	cout<<"Enter edges:\n";
	vector< vector<int> > v(n);
	map< pair<int,int>,int > hmap;
	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin>>c>>a>>b;
		hmap[make_pair(a,b)] = c;
		v[a].push_back(b);
	}
	cout<<"Enter source:\n";
	cin>>s;
	vector<int> dist(n,INT_MIN);
	dist[s] = 0;
	vector<int> visited(n,0);
	stack<int> sta;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs(i,visited,sta,v);
		}
	}
	while(!sta.empty())
	{
		int a = sta.top();
		sta.pop();
		if(dist[a]!=INT_MIN)
		{
			for(i=0;i<v[a].size();i++)
			{
				if(dist[a]+hmap[make_pair(a,v[a][i])]>dist[v[a][i]])
					dist[v[a][i]] = dist[a]+hmap[make_pair(a,v[a][i])];
			}
		}
	}
	for(i=0;i<n;i++)
		cout<<dist[i]<<' ';
	return 0;
}