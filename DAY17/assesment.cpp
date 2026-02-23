#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
struct airport_info
{
	int index;
	string airport_name;
	int cost;
	airport_info(int x,string s,int c)
	{
		index=x;
		airport_name=s;
		cost=c;
	}
};
struct comparator
{
	bool operator()(const pair<int,int>&a,const pair<int,int>&b)
	{
		return a.first>b.first;
	}
};

class airport_map
{
	int v;
	vector<vector<pair<int,int>>>adj;
	public:
	airport_map(int n)
	{
		v=n;
		adj.resize(v);
	}
	void addedge(airport_info a1,airport_info a2,int d)
	{
		adj[a1.index].push_back({a2.index,d});

	}
/*	void print()
	{
		for(auto& x:adj)
		{
			for(auto y:x)
				cout<<y.first.airport_name<<" "<<y.second.airport_name<<" "<<endl;

		}
	}*/

	void shortestpath(int src,vector<airport_info>&airports)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>p;
		vector<int>dis(v,INT_MAX);
		vector<int>total_cost(v,INT_MAX);
		dis[src]=0;
		total_cost[src]=airports[src].cost;
		p.push({0,src});
		while(!p.empty())
		{
			int distance=p.top().first;
			int node=p.top().second;
			p.pop();

			for(auto edge:adj[node])
			{
				int neighbour=edge.first;
				int neighbour_distance=edge.second;
				int new_cost=neighbour_distance+airports[neighbour].cost;
				if(dis[neighbour]>distance+neighbour_distance)
				{
					dis[neighbour]=distance+neighbour_distance;
					total_cost[neighbour]=new_cost;
					p.push({dis[neighbour],neighbour});
				}
			}
		}
		cout<<"source airport  "<<airports[src].airport_name<<"\n\n";
		for(int i=0;i<v;i++)
		{
			if(dis[i]!=INT_MAX)
				cout<<"airpost "<<airports[i].airport_name<<" ->"<<dis[i]<<"km"<<" "<<airports[i].cost<<"$"<<endl;
		}
	}

};


int main()
{
	airport_info a1(0,"Kempegowda",500);
	airport_info a2(1,"Chhatrapati Shivaji",1500);
	airport_info a3(2,"Rajiv Gandhi",1300);
	airport_info a4(3,"Indira Gandhi",4500);
	airport_info a5(4,"Chennai International Airport",900);
	airport_info a6(5,"Netaji Subhas Chandra Bose International Airport",1100);

	vector<airport_info>airports={a1,a2,a3,a4,a5,a6};
	airport_map m(6);
	m.addedge(a1,a3,455);
	m.addedge(a2,a3,1138);
	m.addedge(a4,a2,1140);
	m.addedge(a4,a1,1740);
	m.addedge(a2,a1,840);
	m.addedge(a5,a6,1660);
	m.addedge(a3,a6,620);
//	m.print();
	m.shortestpath(4,airports);
}
