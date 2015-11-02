#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,n;
	cin>>n;
	map<int,int> hmap;
	vector<int> v(n);
	for(i=0;i<n;i++)
	{
		cin>>j;
		v[i] = j;
		if(hmap.find(j)==hmap.end())
		{
			hmap[j]=1;
		}
		else hmap[j]++;
	}
	j = n;

	for(map<int,int> :: iterator it = hmap.begin();it!=hmap.end();it++)
	{
		int a = it->second;
		//cout<<it->second<<'-'<<j<<' ';
		it->second = j-a+1;
		j = j-a;
	}
	for(i=0;i<n;i++)
	{
		//v[i] = hmap[v[i]];
		cout<<hmap[v[i]]<<' ';
	}
	return 0;
}