#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class  dijkras
{
	int v;
	vector<vector<pair<int,int>>>adj;
	public:
	dijkras(int n)
	{
	v=n;
	adj.resize(v);
	}
	void addedge(int src,int dest,int w)
	{
		adj[src].push_back({dest,w});
		adj[dest].push_back({src,w});
	}
	void shortestpath(int src)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
		vector<int>dis(v,INT_MAX);

		dis[src]=0;
		p.push({0,src});

		while(!p.empty())
		{
			int d=p.top().first;
			int node=p.top().second;
			p.pop();

			for(auto edge:adj[node])
			{
				int neighbour_weight=edge.second;
				int neighbour=edge.first;

				if(dis[neighbour]>d+neighbour_weight)
				{
					dis[neighbour]=d+neighbour_weight;
					p.push({dis[neighbour],neighbour});
				}

			}
		}
		for(int i=0;i<v;i++)
		{
			if(dis[i]!=INT_MAX)
				cout<<"shortest paths nodes s "<<i<<" "<<dis[i]<<endl;
		}
	}
};
int main()
{
	dijkras d(8);
	d.addedge(0,2,5);
	d.addedge(0,5,4);
	d.addedge(0,3,3);
	d.addedge(2,4,2);
	d.addedge(2,1,2);
	d.addedge(1,3,2);
	d.addedge(5,1,3);
	d.addedge(5,3,4);
	d.shortestpath(0);
}



