#include <bits/stdc++.h>

using namespace std;

int funct(int n)
{
	int m = 1;
	while(m&n)
	{
		n = n^m;
		m = m<<1;
	}
	return n^m;
}

int main()
{
	int i,n;
	cin>>n;
	cout<<funct(n)<<'\n';
	return 0;
}