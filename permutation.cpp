#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

void swap(char &a,char &b)
{
	char c;
	c = a;
	a = b;
	b = c;
}

void function(string s,int i,int n)
{
	if(i==n)
	{
		cout<<s<<'\n';
	}
	else
	{
		for(int j=i;j<=n;j++)
		{
			swap(s[i],s[j]);
			function(s,i+1,n);
			swap(s[i],s[j]);
		}
	}
}

int main()
{
	string s;
	cin>>s;
	int x = s.length()-1;
	function(s,0,x);
	return 0;
}