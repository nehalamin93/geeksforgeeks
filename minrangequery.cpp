#include <bits/stdc++.h>

using namespace std;

int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
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
		v[index] = min(function(v,arr,si,mid,index*2+1),function(v,arr,mid+1,se,2*index+2));
		return v[index];
	}
}

int get_min(vector<int> v,int si,int se,int l,int r,int index)
{
	if(l<=si && r>=se) return v[index];
	if(l>se || r<si) return INT_MAX;
	int mid = si + (se-si)/2;
	return min(get_min(v,si,mid,l,r,index*2+1),get_min(v,mid+1,se,l,r,2*index+2));
}

int main()
{
	int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int h = (int)ceil(log2(n));
    int n2 = 2*pow(2,h);
    vector<int> v(n2);
    function(v,arr,0,n-1,0);
    for(int i=0;i<n2;i++)
    {
    	cout<<v[i]<<' ';
    }
    cout<<'\n';
    cout<<get_min(v,0,n-1,1,5,0)<<'\n';
	return 0;
}