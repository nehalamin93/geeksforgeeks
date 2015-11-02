#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,n,m,a,b,n1,n2;
	cout<<"Enter n:\n";
	cin>>n;
	vector<int> v(n+1,-1);
	cout<<"Enter no. of ladder (u,v):\n";
	cin>>n1;
	cout<<"Enter ladders(u,v)\n";
	for(i=0;i<n1;i++)
	{
		cin>>a>>b;
		v[a] = b;
	}
	cout<<"Enter no. of snakes (u,v):\n";
	cin>>n1;
	cout<<"Enter snakes(u,v)\n";
	for(i=0;i<n1;i++)
	{
		cin>>a>>b;
		v[a] = b;
	}
	vector<int> visited(n+1,0);
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	vector<int> level(n+1,0);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(i=1;i<=6;i++)
		{
			if(i+p<=n && visited[i+p]==0)
			{
				visited[i+p] = 1;
				if(v[i+p]>=0)
				{
					visited[v[i+p]] = 1;
					q.push(v[i+p]);
					level[v[i+p]] = level[p]+1;
				}
				else
				{ 
					q.push(i+p);
					level[i+p] = level[p]+1;
				}
			}
		}
	}
	cout<<level[30]<<'\n';
	return 0;
}