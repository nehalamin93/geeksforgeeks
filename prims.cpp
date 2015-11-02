#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,k,n,m;
	cout<<"Enter no. of vertices:\n";
	cin>>n;
	cout<<"Enter no. of edges:\n";
	cin>>m;
	cout<<"Enter edges:\n";
	set< pair<int,pair<int,int> > > s;
	vector< vector< pair<int,int> > > v(n);
	for(i=0;i<m;i++)
	{
		int a,b,c,w;
		cin>>w>>a>>b;
		v[a].push_back(make_pair(b,w));
		v[b].push_back(make_pair(a,w));
	}
	vector<int> mst(n,0);
	vector<int> parent(n,0);
	parent[0] = -1;
	mst[0] = 1;
	for(i=0;i<v[0].size();i++)
	{
		s.insert(make_pair(v[0][i].second,make_pair(v[0][i].first,0)));
	}
	while(!s.empty())
	{
		pair<int,pair<int,int> > p = *(s.begin());
		cout<<p.first<<' '<<p.second.first<<' '<<p.second.second<<'\n';

		int a;
		if(mst[p.second.first]==0){ a = p.second.first; parent[a] = p.second.second; }
		else{ a = p.second.second; parent[a] = p.second.first;}

		mst[a] = 1;
		for(i=0;i<v[a].size();i++)
		{
			int a1,b1,c1;
			a1 = a;
			b1 = v[a][i].first;
			if(b1>a1)
			{
				c1 = b1;
				b1 = a1;
				a1 = c1;
			}
			pair<int,pair<int,int> >  qq = make_pair(v[a][i].second,make_pair(a1,b1));
			if(mst[v[a][i].first]==1) s.erase(qq);
			else
			{ 
				s.insert(qq);
			}
		}
	}

	for(i=1;i<n;i++)
	{
		cout<<parent[i]<<'-'<<i<<'\n';
	}

	return 0;
}