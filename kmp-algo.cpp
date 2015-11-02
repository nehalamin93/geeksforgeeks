#include <bits/stdc++.h>

using namespace std;

int kmp(string text,string s)
{
	int n,m,i,j,k;
	n = s.length();
	m = text.length();
	int arr[n];
	//for(i=0;i<n;i++) arr[i] = 0;
	arr[0] = 0;
	j = 0;
	i = 1;
	while(i<n)
	{
		if(s[i]==s[j])
		{
			arr[i] = j+1;
			i++;
			j++;
		}
		else
		{
			while(j!=0 && s[j]!=s[i])
			{
				j = arr[j-1];
			}
			if(s[j]==s[i])
			{
				arr[i] = j+1;
				//cout<<arr[i]<<' '<<j<<'\n';
				i++;
				j++;
			}
			else
			{
				arr[i] = 0;
				i++;
			}
		}
		
	}
	
	i = 0;
	j = 0;
	while(i<n && j<m)
	{
		if(s[i] == text[j])
		{
			i++;
			j++;
		}
		else
		{
			while(i!=0 && s[i]!=text[j])
			{
				i = arr[i-1];
			}
			if(s[i]==text[j])
			{
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}
	}
	if(i==n)
	{
		return j-n;
	}
	else return -1;
}

int main()
{
	int i,j;
	string text,s;
	cout<<"Enter text:\n";
	getline(cin,text);
	cout<<"Enter string to search:\n";
	cin>>s;
	cout<<"Index:\n";
	cout<<kmp(text,s)<<'\n';
}