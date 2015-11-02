#include <bits/stdc++.h>

using namespace std;

int p =0;
int count(int arr[],int ii,int m,int target)
{
	p++;
	//cout<<'*'<<p<<'*';
	if(target==0) return 1;
	else if(target<0 || ii>m) return 0;
	else
	{
		return count(arr,ii+1,m,target)+count(arr,ii,m,target-arr[ii]);
	}
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