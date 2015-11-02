#include <bits/stdc++.h>

using namespace std;

int arr[1000009];
int tree[1000010];

int createtree(int start,int end,int index)
{
	if(start>end) return 0;
	if(start==end)
	{
		tree[index] = arr[start];
		return tree[index];
	}
	int mid = (start+end)/2;
	tree[index] = createtree(start,mid,2*index+1)+createtree(mid+1,end,2*index+2);
	return tree[index];
}

int query(int index,int start,int end,int x,int y)
{
	if(x<=start && y>=end)
		return tree[index];
	if(y<start || x>end)
		return 0;
	int mid = (start+end)/2;
	return query(2*index+1,start,mid,x,y)+query(2*index+2,mid+1,end,x,y);
}

void updateutil(int start,int end,int i,int newval,int index)
{
	if(i<start || i>end) return;
	tree[index] += newval;
	if(start!=end)
	{
		int mid = (start+end)/2;
		updateutil(start,mid,i,newval,2*index+1);
		updateutil(mid+1,end,i,newval,2*index+2);
	}
}

void update(int i,int newval,int n)
{
	newval = newval-arr[i];
	updateutil(0,n-1,i,newval,0);
}

int main()
{
	int i,j,n,m,k,x,y;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		createtree(0,n-1,0);
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			cout<<query(0,0,n-1,x,y)<<'\n';
		}
		update(1,10,n);
		cout<<query(0,0,n-1,1,3);
	}
	return 0;
}