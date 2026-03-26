#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edgedata
{
	int u;
	int v;
	int wt;
};
struct comparator
{
	bool operator()(const edgedata &a,const edgedata& b)const
	{
		return a.wt<b.wt;
	}
};
class krukals
{
	vector<edgedata>edge;
	vector<int>parent;
	vector<int>rank;
	int n;
	public:
	krukals(int x)
	{
		n=x;
		parent.resize(n);
		rank.resize(n);
	}
	void addedge(int u,int v,int w)
	{
		edge.push_back({u,v,w});
	}
	void makeset()
	{
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
	}
	int findparent(int node)
	{
		if(parent[node]==node)
			return node;

		return parent[node]=findparent(parent[node]);
	}
	void unionset(int x,int y)
	{
		x=findparent(x);
		y=findparent(y);

		if(x==y)
			return;

		if(rank[x]<rank[y])
			parent[x]=y;
		else if(rank[x]>rank[y])
			parent[y]=x;
		else
		{
			parent[x]=y;
			rank[x]++;
		}
	}

	void minimum_spanningtree()
	{
		sort(edge.begin(),edge.end(),comparator());
		makeset();

		int weight=0;
		int edgecount=0;
		for(const edgedata &e:edge)
		{
			int x=e.u;
			int y=e.v;
			int w=e.wt;

			if(findparent(x)!=findparent(y))
			{
				unionset(x,y);
				cout<<x<<" -> "<<y<<" cost  "<<w<<endl;

				weight+=w;
				edgecount++;

				if(edgecount==n-1)
					break;
			}
		}
		cout<<"total_weight "<<weight<<endl;
	}
};
int main()
{
	krukals g(6); // 6 nodes
	g.addedge(0,1,4);
	g.addedge(0,2,4);
	g.addedge(1,2,2);
	g.addedge(2,3,3);
	g.addedge(2,5,2);
	g.addedge(2,4,4);
	g.addedge(3,4,3);
	g.addedge(5,4,3);

	g.minimum_spanningtree();
}


