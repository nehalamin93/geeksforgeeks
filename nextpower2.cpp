#include <bits/stdc++.h>

using namespace std;

int func(int n)
{
	int count = 0;
	if(n && n&(n-1))
	{
		while(n>0)
		{
			n = n>>1;
			count++;
		}
		n = 1<<count;
		return n;
	}
	else if(n==0) return 1;
	else if(!(n&(n-1))) return n;
}
int main()
{
	int i,n;
	cin>>n;
	cout<<func(n)<<'\n';
	return 0;
}