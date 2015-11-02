#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	int i,j,k;
	map<char,int> hmapa;
	map<char,int> hmapb;
	map<char,int> hmapc;
	for(i=0;i<a.length();i++)
	{
		if(hmapa.find(a[i])==hmapa.end())
			hmapa[a[i]] = 1;
		else
			hmapa[a[i]]++;
	}
	for(i=0;i<b.length();i++)
	{
		if(hmapb.find(b[i])==hmapb.end())
			hmapb[b[i]] = 1;
		else
			hmapb[b[i]]++;
	}
	for(i=0;i<c.length();i++)
	{
		if(hmapc.find(c[i])==hmapc.end())
			hmapc[c[i]] = 1;
		else
			hmapc[c[i]]++;
	}
	int max = a.length();
	for(map<char,int> :: iterator it = hmapb.begin();it!=hmapb.end();it++)
	{
		if(hmapa.find(it->first)==hmapa.end() || hmapa[it->first]<it->second) 
		{
			max = 0;
			break;
		}
		else
		{
			int p = hmapa[it->first]/it->second;
			if(max>p) max = p;
		}
	}
	int min = 0;
	string s1;
	if(max>min)
	{
		for(i=0;i<b.length();i++)
		{
			hmapa[b[i]]-=max;
		}
		if(hmapa[b[i]]==0) hmapa.erase(b[i]);
		for(i=0;i<max;i++)
		{
			s1+=b;
		}
		min = a.length();
		for(map<char,int> :: iterator it = hmapc.begin();it!=hmapc.end();it++)
		{
			if(hmapa[it->first]<it->second) 
			{
				min = 0;
				break;
			}
			else
			{
				int p = hmapa[it->first]/it->second;
				if(min>p) min = p;
			}
		}
		max = min+max;
		if(min>0)
		{
			for(i=0;i<c.length();i++)
			{
				hmapa[c[i]] = hmapa[c[i]]-min;
			}
			if(hmapa[c[i]]==0) hmapa.erase(c[i]);
			for(i=0;i<min;i++)
			{
				s1+=c;
			}	
		}
	}


	min = a.length();
	for(map<char,int> :: iterator it = hmapc.begin();it!=hmapc.end();it++)
	{
		if(hmapa.find(it->first)==hmapa.end() || hmapa[it->first]<it->second) 
		{
			min = 0;
			break;
		}
		else
		{
			int p = hmapa[it->first]/it->second;
			if(min>p) min = p;
		}
	}
	string s;
	string s2;
	int max1 = 0 ;
	
		for(i=0;i<c.length();i++)
		{
			hmapa[c[i]] = hmapa[c[i]]-min;
		}
		if(hmapa[c[i]]==0) hmapa.erase(c[i]);
		for(i=0;i<min;i++)
		{
			s2+=c;
		}
		max1 = a.length();
		for(map<char,int> :: iterator it = hmapb.begin();it!=hmapb.end();it++)
		{
			if(hmapa[it->first]<it->second) 
			{
				max1 = 0;
				break;
			}
			else
			{
				int p = hmapa[it->first]/it->second;
				if(max1>p) max1 = p;
			}
		}
		if(max1>0)
		{
			for(i=0;i<b.length();i++)
			{
				hmapa[b[i]]-=max1;
			}
			if(hmapa[b[i]]==0) hmapa.erase(b[i]);
			for(i=0;i<max1;i++)
			{
				s2+=b;
			}
		}

	min = min+max1;
	if(min>max) s = s2;
	else s = s1;

	for(map<char,int> :: iterator it = hmapa.begin();it!=hmapa.end();it++)
	{
		for(i=0;i<it->second;i++)
		{
			s+=it->first;
		}
	}
	cout<<s;
	return 0;
}