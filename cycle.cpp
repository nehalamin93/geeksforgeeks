							// Directed Graph
#include <bits/stdc++.h>

using namespace std;

vector<int> visited(100000,0);
vector<int> depart(10000,0);
int t = 0;
void dfs(vector< vector<int> >& v,int a,int &flag)
{
	visited[a] = 1;
	int i,j,n;
	for(i=0;i<v[a].size();i++)
	{
		if(visited[v[a][i]]==0)
			dfs(v,v[a][i],flag);
		else if(depart[v[a][i]]==0)
			flag = 0;
	}
	depart[a] = ++t;
}

int main()
{
	int i,j,m,n;
	cout<<"Enter no. of vertices:\n";
	cin>>n;
	cout<<"Enter no. of edges:\n";
	cin>>m;
	cout<<"Enter Edges:\n";
	vector< vector<int> > v(n);
	for(i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	int flag = 1;
	dfs(v,0,flag);
	if(flag) cout<<"No cycle\n";
	else cout<<"cycle detected\n";
	return 0;
}