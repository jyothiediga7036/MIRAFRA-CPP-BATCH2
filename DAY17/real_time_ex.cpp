#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct node_data
{
	string city;
	int length;
	node_data(string s,int d)
	{
		city=s;
		length=d;
	}
};
struct comparator
{
	bool operator()(node_data&a,node_data&b)
	{
		return a.length>b.length;
	}
};
typedef pair<int, int> vertex;  
class WeightedGraph
{
	int V;
	vector<vector<vertex>> adj;
	vector<string>cityname;

	public:
	WeightedGraph(int vertices)
	{
		V =vertices;
		adj.resize(V);
	}
	void setCityName(int x,string s)
	{
		cityname[x]=s;
	}


	void addEdge(int u,int v,int weight)
	{
		adj[u].push_back({v,weight});
		adj[v].push_back({u,weight});// remove if directed
	}

	void shortestPath(int src) 
	{
		priority_queue<vertex,vector<vertex>,greater<vertex>>pq; //pq minheap
									 //PQ -> {distance,node} // priority_queue<int> pq; bedefault vector
									 //priority_queue<T, c, comp> pq;  T is the data type , c is the underlying container, comp =minheap
		vector<int>dist(V,INT_MAX); // INF INF INF INF INF 
		vector<bool> visited(V, false);
		dist[src] =0;  // 0 INF INF INF INF 
		pq.push(node_data(cityname[src],0)); // 0 0

		while(!pq.empty()) // 1 elmnt
		{
			node_data cur=pq.top();
			pq.pop();
	int node = -1;
            for (int i = 0; i < V; i++) {
                if (cityname[i] == cur.city) {
                    node = i;
                    break;
                }
            }

			if(visited[node_data]) // skip if it is visited
				continue;
			visited[node_data]=true;

			for(auto edge :adj[node]) // adj[0] ={ 1,4} ,{2,1}  AdJ List ->{neighbor,weight}
		{
			int neighbor =edge.first; // 1 {neighbor,weight}
		int weight =edge.second;  // 4

		if(!visited[neighbor] && dist[neighbor] > d+weight) // dist[1]>0+4 ,INF >4
		{
			dist[neighbor] =dis[node]+weight; //  dist[1] =0+4
			pq.push(node_data(cityname[neighbor],dis[neighbor])); //  dist[1],neighbor})
		} // PQ -> {distance,node}
		}
	}

	cout<<"Shortest distances from source "<<src<<":\n";
	for(int i =0;i<V;i++)
		cout<<city[i]<<" = "<<dist[i]<<endl;
}
};

int main() {
	WeightedGraph g(5);
	g.setCityName(0, "Hyd");
	g.setCityName(1, "Knl");
	g.setCityName(2, "Che");
	g.setCityName(3, "Blr");
	g.setCityName(4, "Pune");

	g.addEdge(0,1,4); // 0 -1 (4)
	g.addEdge(0,2,1); // 0 -2 (1)
	g.addEdge(2,1,2); // 0 -2 (1)
	g.addEdge(1,3,1);
	g.addEdge(2,3,5);
	g.addEdge(3,4,3);

	g.shortestPath(0);//src=0

	return 0;
}
