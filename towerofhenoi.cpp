#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

void towerofh(int n,char from,char to,char via)
{
	if(n==1)
	{
		cout<<"move "<<n<<" from "<<from<<" to "<<to<<'\n';
		return;
	}
	towerofh(n-1,from,via,to);
	cout<<"move "<<n<<" from "<<from<<" to "<<to<<'\n';
	towerofh(n-1,via,to,from);
}

int main()
{
	int n;
	cout<<"Enter n:\n";
	cin>>n;
	towerofh(n,'A','C','B');
	return 0;
}