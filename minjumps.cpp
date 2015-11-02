#include <bits/stdc++.h>

using namespace std;

int min(int a,int b)
{
	if(b>a)return a;
	else return b;
}
int minJumps(int arr[],int n)
{
	int i,j;
	vector<int> v(n+1);
	v[0] = 0;
	for(i=1;i<n;i++)
	{
		v[i] = INT_MAX;
		for(j=0;j<i;j++)
		{
			if(i<=j+arr[j])
			{
				v[i] = min(v[i],1+v[j]);
			}
		}
	}
	return v[n-1];
}

int main()
{
	int n,i,j,k;
	int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
	return 0;
}