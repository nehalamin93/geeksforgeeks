#include <bits/stdc++.h>

using namespace std;

bool power4(int n)
{
	int count = 0;
	if(n && !(n&(n-1)))
	{
		while(n>1)
		{
			n = n>>1;
			count++;
		}
		return count%2==0?1:0;
	}
	return 0;
}

int main()
{
	int i,j,n;
	cin>>n;
	cout<<power4(n)<<'\n';
	return 0;
}