#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,m,n;
	cout<<"Enter no of vetices:\n";
	cin>>n;
	cout<<"Enter no. of edges:\n";
	cin>>m;
	cout<<"Enter edges:\n";
	vector<int> v(n,0);
	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin>>c>>a>>b;
		v[a] += -1*c;
		v[b] += c;
	}

	set< pair<int,int> > s;
	for(i=0;i<n;i++)
	{
		if(v[i]!=0) s.insert(make_pair(v[i],i));
	}
	int count = 0;
	while(!s.empty())
	{
		int a = (*s.begin()).first;
		int b = (*s.rbegin()).first;
		pair<int,int> p1,p2;
		p1 = *s.begin();
		p2 = *s.rbegin();
		//cout<<a<<b;
		
		if(-1*a>b)
		{
			cout<<(*s.begin()).second<<" will give "<<b<<" to "<<(*s.rbegin()).second<<'\n';
			s.erase(s.begin());
			s.erase(--s.end());
			p1.first += p2.first;
			s.insert(p1);
		}
		else if(-1*a<b)
		{
			cout<<(*s.begin()).second<<" will give "<<(-1*a)<<" to "<<(*s.rbegin()).second<<'\n';
			s.erase(--s.end());
			s.erase(s.begin());
			p2.first+= p1.first;
			//cout<<p2.first<<' '<<p1.second<<' ';
			s.insert(p2);
		}
		else
		{
			cout<<(*s.begin()).second<<" will give "<<b<<" to "<<(*s.rbegin()).second<<'\n'<<"*";
			s.erase(s.begin());
			s.erase(--s.end());
		}
		cout<<s.size()<<'\n';
		//count++;
		//if(count==2) break;
	}
	return 0;
}