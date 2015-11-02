#include <bits/stdc++.h>

using namespace std;

void createtree(int arr[][2],int start,int end,int index)
{
	if(start>end) return;
	if(start==end)
	{
		arr[index][0] = start;
		return;
	}
	int mid = (start+end)/2;
	arr[index][0] = mid;
	createtree(arr,start,mid-1,index*2);
	createtree(arr,mid+1,end,2*index+1);
}

void update(int arr[][2],int x,int val,int count)
{
	int i,j;
	i =1;
	while(i<count && arr[i][0]>0)
	{
		if(arr[i][0]==x) 
		{
			arr[i][1] += val;
			break; 
		}
		else if(arr[i][0]>x)
		{
			arr[i][1] += val;
			i = 2*i; 
		}
		else
		{
			i = 2*i +1;
		}
	}
}

int search(int arr[][2],int val,int count)
{
	int i,j;
	i =1;
	while(i<count && arr[i][0]>0)
	{
		if(val<arr[i][1])
		{
			if(2*i<count && arr[i][0]!=0)
			{
				i = 2*i;
			}
			else
			{
				return arr[i][0];
			}
		}
		else if(val==arr[i][1])
		{
			return arr[i][0];
		}
		else
		{
			val = val-arr[i][1];
			i = i*2 +1;
		}
	}
	return -1;
}

int main()
{
	int i,j,n,q;
	cin>>n>>q;
	int count =1;
	int a = n;
	while(a>0)
	{
		count = count<<1;
		a = a>>1;
	}
	int arr[count][2];

	for(i=0;i<count;i++)
	{
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
	createtree(arr,1,n,1);
	for(i=0;i<q;i++)
	{
		int w,x,val;
		scanf("%d",&w);
		if(w==0)
		{
			scanf("%d%d",&x,&val);
			update(arr,x,val,count);
			for(j=1;j<count;j++)
			{
				cout<<arr[j][0]<<' '<<arr[j][1]<<'\n';
			}
		}
		else
		{
			scanf("%d",&val);
			cout<<search(arr,val,count)<<'\n';
		}
	}
	/*for(i=1;i<count;i++)
	{
		cout<<arr[i][0]<<' ';
	}*/
	return 0;
}