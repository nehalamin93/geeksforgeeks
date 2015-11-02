#include <bits/stdc++.h>

using namespace std;

int min(int a,int b)
{
	return a>b?b:a;
}

int function(int n)
{
	int *a;
	a = (int *)malloc((n+1)*sizeof(int));
	int i,j;
	int i1=0,i2=0,i3=0;
	a[0] = 1;
	for(i=1;i<n;i++)
	{
		a[i] = min(a[i1]*2,min(a[i2]*3,a[i3]*5));
		cout<<a[i]<<' ';
		if(a[i]==a[i1]*2) i1++;
	    if(a[i]==a[i2]*3) i2++;
		if(a[i]==a[i3]*5) i3++;
	}
	return a[n-1];
}

int main()
{
	int n,i;
	cin>>n;
	cout<<"\nUgly number= "<<function(n)<<'\n';
	return 0;
}