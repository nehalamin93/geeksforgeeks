#include <bits/stdc++.h>

using namespace std;

int function(vector<int>& v,int arr[],int si,int se,int index)
{
	if(si==se)
	{
		v[index] = arr[si];
		return v[index];
	}
	else
	{
		int mid = si + (se-si)/2;
		v[index] = function(v,arr,si,mid,2*index+1)+function(v,arr,mid+1,se,2*index+2);
		return v[index];
	}
}

int func_sum(vector<int> v,int si,int se,int l,int r,int index)
{
	if(l<=si && r>=se)
	{
		return v[index];
	}
	else if(r<si || l>se)
	{
		return 0;
	}
	else
	{
		int mid = si + (se-si)/2;
		return func_sum(v,si,mid,l,r,2*index+1)+func_sum(v,mid+1,se,l,r,2*index+2);
	}
}

void update(vector<int>& v,int arr[],int i,int val,int index,int diff,int si,int se)
{
	if(i>se || i<si)
	{
		return;
	}
	v[index] += diff;
	if(se!=si)
	{
		int mid = si + (se-si)/2;
		update(v,arr,1,10,2*index+1,diff,si,mid);
		update(v,arr,1,10,2*index+2,diff,mid+1,se);
	}
}
int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int  n = sizeof(arr)/sizeof(arr[0]);
	int h = (int)(ceil(log2(n)));
	int n2 = 2*pow(2,h);
	vector<int> v(n2);
	function(v,arr,0,n-1,0);
	for(int i=0;i<n2;i++)
	{
		cout<<v[i]<<' ';
	}
	cout<<'\n';
	cout<<func_sum(v,0,n-1,1,3,0)<<'\n';
	int diff = 10-arr[1];
	update(v,arr,1,10,0,diff,0,n-1);
	for(int i=0;i<n2;i++)
	{
		cout<<v[i]<<' ';
	}
	cout<<'\n';
	cout<<func_sum(v,0,n-1,1,3,0)<<'\n';
	return 0;
}