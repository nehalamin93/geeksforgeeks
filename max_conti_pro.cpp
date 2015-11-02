#include <bits/stdc++.h>

using namespace std;

int min1(int a,int b)
{
	return a>b?b:a;
}
int max1(int a,int b)
{
	return a>b?a:b;
}

int function(vector<int> v,int n)
{
	vector<int> min(n);
	vector<int> max(n);
	if(n==0) return 0;
	min[0] = v[0];
	max[0] = v[0];
	for(int i=1;i<n;i++)
	{
		if(v[i]>0)
		{
			max[i] = max1(max[i-1]*v[i],v[i]);
			min[i] = min1(min[i-1]*v[i],v[i]);
 		}
		else if(v[i]==0)
		{
			max[i] = 0;
			min[i] = 0;
		}
		else
		{
			max[i] = max1(v[i],v[i]*min[i-1]);
			min[i] = min1(v[i],max[i-1]*v[i]);
		}
	}
	int m = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(m<max[i]) m = max[i];
	}
	return m;
}

int main()
{
	int i,j,k,n;
	vector<int> v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>j;
		v.push_back(j);
	}
	cout<<"max cont. product= "<<function(v,n)<<'\n';
	return 0;
}