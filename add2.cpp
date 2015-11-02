#include <bits/stdc++.h>

using namespace std;

int sum(int a,int b);

int main()
{
	int m,n;
	cin>>m>>n;
	cout<<sum(m,n)<<'\n';
	return 0;
}

int sum(int a,int b)
{
	if(a==0) return b;
	if(b==0) return a;
	while(b!=0)
	{
		int carry = a&b;
		a = a^b;
		b = carry<<1;	
	}
	return a;
}