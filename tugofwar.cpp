#include <bits/stdc++.h>

using namespace std;

int mod(int a)
{
	if(a<0) return -1*a;
	else return a;
}

vector<int> function(int arr[],int n)
{
	int i,j,k;
	//cout<<'*';
	int p = pow(2,n);
	int min = INT_MAX;
	int s = 0;
	for(i=0;i<n;i++)
		s+=arr[i];
	cout<<s<<'\n';
	vector<int> result;
	for(i=0;i<p;i++)
	{
		int sum = 0,count=0;
		vector<int> v;
		//cout<<n;
		for(j=0;j<n;j++)
		{
			if((i & 1<<j) && count<n/2)
			{
				count++;
				sum+=arr[j];
				//cout<<sum<<' ';
				v.push_back(arr[j]);
			}
			if(count>=n/2) break;
		}
		if(count==n/2)
		{
			int s2 = s-sum;
			if(mod(s2-sum)<min)
			{
				min = mod(s2-sum);
				result = v;
				// for(int i=0;i<result.size();i++)
    // 			{
    // 				cout<<result[i]<<' ';
    // 			}
			}
		}
		v.clear();
	}
	return result;
}

int main()
{
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    //cout<<n<<' ';
    vector<int> r = function(arr,n);
    for(int i=0;i<r.size();i++)
    {
    	cout<<r[i]<<' ';
    }
    cout<<'\n';
	return 0;
}