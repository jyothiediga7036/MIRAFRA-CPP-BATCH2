#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
enum names{traffic_control,power_grid,water_supply,hospital_network,police_control,data_center};
struct control_stations
{
	int station1;
	int station2;
	int cost;
};
bool comparator(const control_stations &a,const control_stations &b)
{
	return a.cost < b.cost;
}

void makeset(vector<int>&parent,vector<int>&rank,int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}
int findparent(vector<int>&parent,int node)
{
	if(parent[node]==node)
		return node;

	return parent[node]=findparent(parent,parent[node]);
}
void unionset(int u,int v,vector<int>&parent,vector<int>&rank)
{
	u=findparent(parent,u);
	v=findparent(parent,v);
	if(u==v)
		return;
	if(rank[u]<rank[v])
		parent[u]=v;
	else if(rank[v]<rank[u])
		parent[v]=u;
	else
	{
		parent[v]=u;
		rank[u]++;
	}
}
int minimum_spanningtree(vector<control_stations>&city,int n)
{
	sort(city.begin(),city.end(),comparator);

	vector<int>parent(n);
	vector<int>rank(n);
	makeset(parent,rank,n);

	int weight=0;
	int edgecount=0;
	string controls[]={"traffic control","power grid","water supply","hospital network","police control","data center"};

	for(const control_stations &c : city)
	{
		int u=c.station1;
		int v=c.station2;
		int cost=c.cost;
		if(findparent(parent,u)!=findparent(parent,v))
		{
			unionset(u,v,parent,rank);
			cout<<controls[u]<<" --->  "<<controls[v]<<"  cost "<<cost<<endl;
			weight+=cost;
			edgecount++;
			if(edgecount==n-1)
				break;
		}
	}
	return weight;
}
int main()
{
	int v=6;
	vector<control_stations>city={
		{0, 1, 4},
		{0, 2, 4},
		{1, 2, 2},
		{2, 3, 3},
		{2, 5, 2},
		{2, 4, 4},
		{3, 4, 3},
		{5, 4, 3}
	};

	int min_weight=minimum_spanningtree(city,v);
	cout<<"total weight is: "<<min_weight<<endl;
}
/* output

power grid --->  water supply  cost = 2
water supply --->  data center  cost =2
water supply --->  hospital network  cost =3
hospital network --->  police control  cost = 3
traffic control --->  power grid  cost= 4

total weight is: 14
*/
