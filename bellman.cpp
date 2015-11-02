#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,n,m;
	cout<<"Enter no of vertices:\n";
	cin>>n;
	cout<<"Enter no of edges:\n";
	cin>>m;
	cout<<"Enter edges:\n";
	vector< vector<int> > v(m,vector<int>(3));
	for(i=0;i<m;i++)
	{
		cin>>v[i][0]>>v[i][1]>>v[i][2];
	}
	vector<int> dist(n,INT_MAX);
	dist[0] = 0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m;j++)
		{
			if(dist[v[j][0]]<INT_MAX && dist[v[j][1]]>dist[v[j][0]]+v[j][2])
			{
				dist[v[j][1]] = dist[v[j][0]]+v[j][2];
			}
		}
		
	}
	for(i=0;i<n;i++)
	{
		cout<<i<<' '<<dist[i]<<'\n';
	}
	return 0;
}