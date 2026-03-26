#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void prims_mst(int v,vector<pair<pair<int,int>,int>>&res)
{

vector<vector<pair<int,int>>> adj(v);   //to convert the adjcency list 

for(auto e : res)
{
    int u = e.first.first;
    int v = e.first.second;
    int w = e.second;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});  // because undirected
}	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
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
			continue;    // priority queue may contain duplicates vertices with same name

		visited[u]=true;
		for(auto it:adj[u])
		{
			int weight=it.second;
			int v=it.first;
			if(!visited[v]&&weight<dis[v])
			{
				dis[v]=weight;
				p.push({dis[v],v});
				parent[v]=u;

			}
		}
	}
	cout<<" minimum spanning tree is "<<endl;
	for(int x=0;x<v;x++)
	{
		if(parent[x]!=-1)
		cout<<parent[x]<<" ->  "<<x<<" weight :"<<dis[x]<<endl;
	}
	
	int total_weight=0;
	
	for(int i=2;i<v;i++)
	{
	total_weight+=dis[i];
	}
	cout<<"total_weight :"<<total_weight<<endl;
}
int main()
{
	int v=6;
	vector<pair<pair<int,int>,int>> edges = {     // only edge list
		{{1,2}, 2}, // <u=1,v=2 >,w=2
		{{1,3}, 3},
		{{2,3}, 1},
		{{2,4}, 4},
		{{3,4}, 5},
		{{4,5}, 7}
	};
	prims_mst(v,edges);  //Edge List  →  Adjacency List  →  Run Prim’s

// prims algorithm wants to adjacency list withot this wont work 
//bcoz based on neighbour nodes it will work  
}


