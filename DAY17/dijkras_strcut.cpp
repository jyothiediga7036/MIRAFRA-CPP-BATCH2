#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct city
{
int index;
string city_name;
string famous_p;
city(int x,string s,string p)
{
index=x;
city_name=s;
famous_p=p;
}
};
class  graph
{
	int v;
	vector<vector<pair<int,int>>>adj;
	public:
	graph(int n)
	{
	v=n;
	adj.resize(v);
	}
	void addedge(city src,city dest,int w)
	{
		adj[src.index].push_back({dest.index,w});
		adj[dest.index].push_back({src.index,w});
	}
	void shortestpath(int src,vector<city>&cities)
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
				cout<<cities[i].city_name<<"->"<<cities[i].famous_p<<" "<<"distance: "<<dis[i]<<endl;
		}
	}
};
int main()
{
city c1 = {0, "Kurnool", "Belum Caves"};
    city c2 = {1, "Orvakal", "Rock Garden"};
    city c3 = {2, "Adoni", "Adoni Fort"};
    city c4 = {3, "Dhone", "Dhone Fort"};
    city c5={4,"hyderabad","peddama gudi"};

    vector<city> cities = {c1, c2, c3, c4,c5};

    graph g(7);

    g.addedge(c1, c2, 50);
    g.addedge(c2, c3, 40);
    g.addedge(c3, c4, 60);
    g.addedge(c1, c4, 120);
    g.addedge(c5,c1,110);
    g.addedge(c2,c5,145);
    g.addedge(c5,c3,90);

    g.shortestpath(2, cities);
	
}



