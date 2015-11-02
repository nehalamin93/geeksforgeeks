#include <bits/stdc++.h>

using namespace std;

int p =0;
int count(int arr[],int ii,int m,int target)
{
	vector<int> v(target+1);
	v[0] = 1;
	for(int i=0;i<=m;i++)
	{
		for(int j=arr[i];j<=target;j++)
		{
			v[j] += v[j-arr[i]];
			//cout<<v[j]<<' ';
		}
		for(int j=0;j<=target;j++)
			cout<<v[j]<<' ';
		cout<<'\n';
	}
	return v[target];
}

int main()
{
    int i, j;
    int arr[] = {5, 2, 3,6};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr,0, m-1, 10));
    getchar();
    return 0;
}