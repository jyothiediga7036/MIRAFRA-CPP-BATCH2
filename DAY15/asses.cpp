#include<iostream>
#include<list>
#include<map>
#include<iomanip>
#include<climits>
using namespace std;
class city_network
{
	map<string,list<pair<string,int>>>root;
	public:
	void addconnection(string src,string dest,int dis)
	{
		root[src].push_back({dest,dis});
		root[dest].push_back({src,dis});
	}
	void show_available_city()const
	{
		for(const auto&x:root)
		{
			cout<<x.first<<"->  ";
			for(const auto&p:x.second)
			{
				cout<<"["<<p.first<<" "<<p.second<<"km"<<"]"<<std::setw(2)<<"->";
			}
			cout<<"null"<<endl;
		}
		cout<<endl;
	}
	void search_nearest_city(string s)
	{
		if(root.find(s)==root.end())
		{
			cout<<"city"<<std::setw(3)<<std::left<<s<<" not prasent in the graph"<<endl;
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
			cout<<"nearest city is "<<p<<"  distance ="<<m<<"km"<<endl<<endl;
		else
			cout<<"no connected citis found"<<endl;
	}
};
int main()
{
	city_network network;
	 network.addconnection("Bengaluru", "Koramangala", 8);
    network.addconnection("Koramangala", "Whitefield", 15);
    network.addconnection("Whitefield", "MG Road", 18);
    network.addconnection("MG Road", "Indiranagar", 6);
    network.addconnection("Indiranagar", "Jayanagar", 10);
    network.addconnection("Jayanagar", "Banaswadi", 12);
    network.addconnection("Banaswadi", "Electronic City", 20);
    network.addconnection("Electronic City", "Hebbal", 25);
    network.addconnection("Hebbal", "Banashankari", 22);
	cout<<"show me available petrol bunks"<<endl;
	network.show_available_city();
	cout<<"nearest petrol bunk for jayanagar"<<endl;
	network.search_nearest_city("Jayanagar");
	
	cout<<"nearest petrol bunk for raydurg"<<endl;
	network.search_nearest_city("raydurg");


}

