#include <bits/stdc++.h>

using namespace std;

void decrease(set< pair<int,int> >& s,int n,int a,vector<int>& dist)
{
	s.erase(make_pair(dist[n],n));
	dist[n] = a;
	s.insert(make_pair(dist[n],n));
}

int main()
{
	int i,j,k,n,m,source;
	cout<<"Enter no. of vertices:\n";
	cin>>n;
	cout<<"Enter no. of edges\n";
	cin>>m;
	cout<<"Enter edge with their lengths\n";
	map< pair<int,int>,int > hmap;
	vector< vector<int> > v(n);
	for(i=0;i<m;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c;
		v[a].push_back(b);
		v[b].push_back(a);
		hmap[make_pair(a,b)] = c;
		hmap[make_pair(b,a)] = c;
	}
	vector<int> dist(n,INT_MAX);
	vector<int> mstset(n,0);
	set< pair<int,int> > s;
	for(i=0;i<n;i++) s.insert(make_pair(dist[i],i));
	//cout<<(*(s.begin())).first<<'-'<<(*(s.begin())).second<<'\n';
	cout<<"Enter source:\n";
	cin>>source;

	s.erase(make_pair(INT_MAX,source));
	s.insert(make_pair(0,source));
	dist[source] = 0;
	//cout<<(*(s.begin())).first<<'-'<<(*(s.begin())).second<<'\n';
	while(!s.empty())
	{
		pair<int,int> p = *(s.begin());
		s.erase(p);
		int v1 = p.second;
		mstset[v1] = 1;
		for(i=0;i<v[v1].size();i++)
		{
			if(mstset[v[v1][i]]==0)
			{
				int c;
				c = min(dist[v[v1][i]],dist[v1]+hmap[make_pair(v1,v[v1][i])]);
				s.erase(make_pair(dist[v[v1][i]],v[v1][i]));
				dist[v[v1][i]] = c;
				s.insert(make_pair(c,v[v1][i]));
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<i<<"-"<<dist[i]<<'\n';
	}
	return 0;
}