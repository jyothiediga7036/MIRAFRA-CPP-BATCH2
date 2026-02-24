#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
enum names{
	Engine_Control=1,
	Battery_Management,
	Dashboard,
	ADAS_Camera,
	Rear_Parking_Sensor,
	Infotainment
};
class car_network
{
	int v;
	vector<vector<pair<int,int>>>vehicle;
	public:
	car_network(int n)
	{
		v=n;
		vehicle.resize(v);
	}
	void add_ECU(int u,int v,int w)
	{
		vehicle[u].push_back({v,w});
		vehicle[v].push_back({u,w});

	}
	void prims_tofind_mst()
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
		vector<bool> visited(v,false);
		vector<int>parent(v,-1);
		vector<int>cable_cost(v,INT_MAX);

		cable_cost[1]=0;
		p.push({0,1});
		while(!p.empty())
		{
			int u=p.top().second;
			p.pop();

			if(visited[u])
				continue;

			visited[u]=true;
			for(auto route:vehicle[u])
			{
				int v=route.first;
				int cost=route.second;

				if(!visited[v]&&cost<cable_cost[v])
				{
					cable_cost[v]=cost;
					parent[v]=u;
					p.push({cable_cost[v],v});
				}
			}
		}
		string ecu_names[] =
		{
			"unused",
			"Engine Control",
			"Battery Management",
			"Dashboard",
			"ADAS_Camera",
			"Rear Parking Sensor",
			"Infotainment"
		};

		cout<<" minimum spanning tree "<<endl;
		for(int i=1;i<v;i++)
		{
			if(parent[i]!=-1)
				cout<<ecu_names[parent[i]]<<"  ->  " <<ecu_names[i]<<" cost: "<<cable_cost[i]<<endl;
		}

		cout<<"total cable cost is"<<endl;
		int total=0;
		for(int i=1;i<v;i++)
			total+=cable_cost[i];

		cout<<"total_cost "<<total<<endl;
	}

};
int main()
{
	car_network c(7);
	c.add_ECU(1,2,3);
	c.add_ECU(1,3,4);
	c.add_ECU(2,3,2);
	c.add_ECU(2,4,6);
	c.add_ECU(3,4,5);
	c.add_ECU(3,5,7);
	c.add_ECU(4,6,4);
	c.add_ECU(5,6,3);

	c.prims_tofind_mst();
}
/*1-2 : 3
  1-3 : 4
  2-3 : 2
  2-4 : 6
  3-4 : 5
  3-5 : 7
  4-6 : 4
  5-6 : 3*/
