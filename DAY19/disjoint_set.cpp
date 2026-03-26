#include<iostream>
#include<vector>
using namespace std;
void printdsu(vector<int>&parent,vector<int>&rank)
{
cout<<"parent :"<<" ";
for(auto x:parent)
cout<<x<<" ";

cout<<endl;

cout<<"rank :"<<" ";
for(auto y:rank)
cout<<y<<" ";

cout<<endl;
cout<<"--------------------------------------------"<<endl;
}
void makeunion(vector<int>&parent,vector<int>&rank,int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}
int findparent(vector<int>& parent, int node)
{
	if(parent[node]==node)
		return node;

	return parent[node]=findparent(parent,parent[node]); // path compression
}

void unionset(int u,int v,vector<int>&parent,vector<int>&rank)
{
	u=findparent(parent,u);
	v=findparent(parent,v);
	if(u==v)
	{
		cout<<"nodes" <<u<<"and "<<v<<"are already in same set"<<endl;
	}
	if(rank[u]<rank[v])
	{
		parent[u]=v;
	}
	else if(rank[u]>rank[v])
	{
		parent[v]=u;
	}
	else
	{
		parent[v]=u;
		rank[u]++;
	}
	cout<<"union done between "<<u<<"and"<< v<<endl;
	printdsu(parent,rank);
}

int main()
{
	int v=7;
	vector<int>parent(v);
	vector<int>rank(v);

	makeunion(parent,rank,v);
	
	printdsu(parent,rank);
	
	unionset(0,1,parent,rank);
	unionset(1,2,parent,rank);
	unionset(3,4,parent,rank);
	unionset(5,6,parent,rank);
	unionset(2,6,parent,rank);

	cout<<"check connectivity "<<endl;
	if(findparent(parent,0)==findparent(parent,6))
	{
		cout<<"0 and 6 are connectd"<<endl;
	}
	else
	cout<<"0 and 6 not connected"<<endl;
	
	if(findparent(parent,2)==findparent(parent,4))
	{
	cout<<"2 and 4 are connectd"<<endl;
	}
	else
	{
	cout<<"2 and 4 are not connected"<<endl;
		cout<<"the parents :"<<findparent(parent,2)<<" "<<findparent(parent,4)<<endl;
		}
}
	


