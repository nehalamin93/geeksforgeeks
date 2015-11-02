#include <bits/stdc++.h>

using namespace std;

struct node
{
	int v;
	int n;
	struct node* next;
};

struct node* find(int x,vector<struct node*>& v)
{
	int i,j;
	struct node *p;
	p = v[x];
	if(p->next==NULL) return p;
	else
	{
		p->next = find(p->next->v,v);
		return p->next;
	}
}

int main()
{
	int i,j,n,m;
	cout<<"No. of vertex:\n";
	cin>>n;
	vector<struct node* > v(n);
	for(i=0;i<n;i++)
	{
		v[i] = (struct node*)malloc(sizeof(struct node));
		v[i]->v = i;
		v[i]->n = 1;
		v[i]->next = NULL;
	}
	cout<<"Enter no. of edges:\n";
	cin>>m;
	vector< vector<int> > val(m,vector<int>(3));
	for(i=0;i<m;i++)
	{
		cin>>val[i][0]>>val[i][1]>>val[i][2];
	}
	sort(val.begin(),val.end());
	vector< vector<int> > arr;
	for(i=0;i<m;i++)
	{
		struct node* x = find(val[i][1],v);
		struct node* y = find(val[i][2],v);
		if(x==y)
		{
			
		}
		else
		{
			vector<int> a(3);
			a[0] = val[i][0];
			a[1] = val[i][1];
			a[2] = val[i][2];
			arr.push_back(a);
			a.clear();
			if(x->n>y->n)
			{
				y->next = x;
				x->n = y->n+x->n;
			}
			else if(x->n<y->n)
			{
				x->next = y;
				y->n = y->n+x->n;
			}
			else 
			{
				x->next = y;
				y->n = y->n+x->n;
			}
		}
	}
	for(i=0;i<arr.size();i++)
	{
		cout<<arr[i][0]<<'-'<<arr[i][1]<<'-'<<arr[i][2]<<'\n';
	}
	return 0;
}