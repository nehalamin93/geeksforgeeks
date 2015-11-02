#include <bits/stdc++.h>

using namespace std;

void function(int weights[],int target,int n)
{
	int i,j;
	int p = pow(2,n);
	//cout<<p<<' '<<n;
	for(i=0;i<p;i++)
	{
		//cout<<'*';
		int sum = 0;
		vector<int> v;
		for(j=0;j<n;j++)
		{
			if(i & 1<<j)
			{
				sum+=weights[j];
				v.push_back(weights[j]);

				if(sum>target) break;
			}
		}
		if(sum==target)
		{
			for(int k=0;k<v.size();k++)
				cout<<v[k]<<' ';
			cout<<'\n';
		}
		v.clear();
	}
}

int main()
{
	int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;
    int n = sizeof(weights)/sizeof(weights[0]);
    vector<int> v(n);	
    function(weights,target,n);
	return 0;
}

