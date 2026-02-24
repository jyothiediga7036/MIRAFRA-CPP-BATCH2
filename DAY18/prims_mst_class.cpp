#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class  prims
{
	int v;
	vector<vector<pair<int,int>>>adj;
	public:
	prims(int n)
	{
		v=n;
		adj.resize(v);
	}
	void addedge(int src,int dest,int w)
	{
		adj[src].push_back({dest,w});
		adj[dest].push_back({src,w});
	}
	void mst_prims()
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
		vector<int>dis(v+1,INT_MAX);
		vector<bool>visited(v+1,false);
		vector<int>parent(v+1,-1);
		dis[1]=0;
		p.push({0,1});

		while(!p.empty())
		{
			int u=p.top().second;
			p.pop();
			if(visited[u])
				continue;

			visited[u]=true;
			for(auto edge:adj[u])
			{
				int weight=edge.second;
				int v=edge.first;
				if(!visited[v]&&weight<dis[v])
				{
					dis[v]=weight;
					p.push({dis[v],v});
					parent[v]=u;

				}
			}
		}
		for(int i=0;i<v;i++)
		{
			if(parent[i]!=-1)
				cout<<parent[i]<<" -> "<<i<<"weight :"<<dis[i]<<endl;
		}

	}
};
int main()
{
	prims d(6);
	d.addedge(1,2,2);
	d.addedge(1,3,3);
	d.addedge(2,3,1);
	d.addedge(2,4,4);
	d.addedge(3,4,5);
	d.addedge(4,5,7);
	d.mst_prims();
}



