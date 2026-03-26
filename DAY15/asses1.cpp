#include<iostream>
#include<list>
#include<map>
#include<iomanip>
#include<climits>
using namespace std;
class delivarygraph
{
	map<string,list<pair<string,int>>>root;
	public:
	void addEdge(string src,string dest,int dis)
	{
		root[src].push_back({dest,dis});
	}
	void show_available_delivary()const
	{
		for(const auto&x:root)
		{
			cout<<x.first<<"->  ";
			for(const auto&p:x.second)
			{
				cout<<"["<<p.first<<" "<<p.second<<"min"<<"]"<<std::setw(2)<<",";
			}
			cout<<"null"<<endl;
		}
		cout<<endl;
	}
	void search_nearest_time(string s)
	{
		if(root.find(s)==root.end())
		{
			cout<<"city"<<std::setw(3)<<std::left<<s<<" not present in the graph"<<endl;
			return;
		}
		int m=INT_MAX;
		string p="";
		for(auto&x:root)
		{
			if(x.first==s)
			{
				for(auto&d:x.second)
				{
					if(m>d.second)
					{
						m=d.second;
						p=d.first;
					}
				}
			}
		}
		if(p!="")
			cout<<"nearest delivary is "<<p<<"  time :"<<m<<"min"<<endl<<endl;
		else
			cout<<"delivary not available this place "<<endl;
	}
};
int main()
{
	delivarygraph dg;
	dg.addEdge("Warehouse", "Hub", 10);
    dg.addEdge("Warehouse", "Customer A", 15);
    dg.addEdge("Hub", "Customer A", 5);
    dg.addEdge("Hub", "Customer B", 8);
    dg.addEdge("Customer A", "Customer B", 6);
    dg.addEdge("Customer B", "Warehouse", 20);
    dg.addEdge("Customer A", "Customer C", 10);
    dg.addEdge("Customer B", "Customer C", 12);
	cout<<"show me availabl delivaries"<<endl;
	dg.show_available_delivary();
	cout<<"shortest time Werehouse "<<endl;
	dg.search_nearest_time("Customer A");
	
	cout<<"shortest time hub "<<endl;
	dg.search_nearest_time("Hub");

}

