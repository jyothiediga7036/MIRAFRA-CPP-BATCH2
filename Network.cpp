#include "Network.h"
#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>


#define RESET "\033[0m"
#define BOLD "\033[1m"

#define MAGENTA  "\033[35m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define PURPLE   "\033[34m"
#define BROWN   "\033[33m"  
#define YELLOW  "\033[93m"
#define DBLUE    "\033[96m"
#define LBLUE    "\033[36m"
#define ORANGE "\033[38;5;208m"

//----------------------------------------------------------------------------------------------

NetworkController::NetworkController(int size)
{
	RouterSize = size;
	std::cout<< BOLD << ORANGE << "\nNetwork Controller Created for SBI Banking!! \n" <<RESET <<std::endl;
}

//-----------------------------------------------------------------------------------------------

NetworkController :: ~NetworkController()
{
	std::cout << BOLD << RED <<"\nNETWORK CONTROLLER DESTROYED for SBI Banking!!" << RESET <<std::endl;
}

//-------------------------------------------------------------------------------------------------
void NetworkController::loadRouters(std::vector<Router> &r )
{

	for(auto &router : r)
	{
		addRouter(router);
	}
}

//-----------------------------------------------------------------------------------------------------

void NetworkController::addRouter(const Router& r)
{
	allRouters.push_back(r);
	routerdata[r.IpAddr] = r;
	Links[r.IpAddr];
}

//----------------------------------------------------------------------------------------------

void NetworkController::addLinks(const Router& r1,const Router& r2)
{
	int cost = costEstimation(r1,r2);

	Links[r1.IpAddr].push_back({r2.IpAddr,cost});
	Links[r2.IpAddr].push_back({r1.IpAddr,cost});  // undirected graph
}

//-----------------------------------------------------------------------------------------------------

bool NetworkController::findOldIP(std::string oldIP){
	if(Links.find(oldIP) != Links.end()){
		return true;
	}
	return false;
}

//-------------------------------------------------------------------------------------------------------------

void NetworkController::connectAllRouters()
{

	addLinks(allRouters[0], allRouters[9]);
	addLinks(allRouters[0], allRouters[4]);
	addLinks(allRouters[0], allRouters[3]);
	addLinks(allRouters[4], allRouters[5]);
	addLinks(allRouters[4], allRouters[6]);
	addLinks(allRouters[6], allRouters[5]);
	addLinks(allRouters[6], allRouters[9]);
	addLinks(allRouters[6], allRouters[1]);
	addLinks(allRouters[5], allRouters[3]);
	addLinks(allRouters[5], allRouters[9]);
	addLinks(allRouters[9], allRouters[7]);
	addLinks(allRouters[9], allRouters[2]);
	addLinks(allRouters[1], allRouters[9]);
	addLinks(allRouters[7], allRouters[8]);
	addLinks(allRouters[7], allRouters[3]);
	addLinks(allRouters[7], allRouters[2]);
	addLinks(allRouters[8], allRouters[3]);
	addLinks(allRouters[8], allRouters[1]);
	addLinks(allRouters[2], allRouters[1]);


	std::cout << GREEN << "Routing Engine Created for SBI Banking!!" << RESET << std::endl;
}

//-------------------------------------------------------------------------------------------------

void NetworkController::generateDotFile()
{
    std::ofstream file("network.dot");

    file << "graph SBI_Network {\n";
    file << "layout=neato;\n";
    file << "overlap=false;\n";
    file << "splines=true;\n";

    file << "node [shape=ellipse style=filled fillcolor=lightblue];\n";

    for(auto &router : Links)
    {
        std::string src = router.first;

        for(auto &nbr : router.second)
        {
            std::string dest = nbr.first;
            int cost = nbr.second;

            if(src < dest) // avoid duplicates
            {
                file << "\"" << routerdata[src].Location << "\" -- "
                     << "\"" << routerdata[dest].Location << "\" "
                     << "[label=\"" << cost << "\"];\n";
            }
        }
    }

    file << "}\n";

    file.close();
}

//-----------------------------------------------------------------------------------------------------------

void NetworkController::DisplayRoutes()
{
	std::cout<<BOLD<<GREEN<<"\nNetwork Connections(Neighbors) :"<<std::endl;
	std::cout<<"----------------------------------"<<RESET<<std::endl;

	for(auto &x : Links)
	{
		auto it = routerdata.find(x.first);
		if(it != routerdata.end()){
			std::cout<<YELLOW<< x.first << "("<< it->second.Location<< ")" << BOLD << DBLUE<<" --> " << RESET ;
		}

		for(auto &y : x.second)
		{
			auto it = routerdata.find(y.first);
			if(it != routerdata.end()){

				std::cout<< y.first << "(" << it->second.Location<<" ,";
			}
			std::cout<<"₹"<<y.second<<" ), ";
		}
		std::cout<<"\n\n" << RESET;
	}
}

//------------------------------------------------------------------------------------------------------

int NetworkController::costEstimation(const Router& r1,const Router& r2)
{
	double lat = r1.Latitude - r2.Latitude;
	double lon = r1.Longitude - r2.Longitude;

	double latDist = lat * 111132;
	double lonDist = lon * 111320 * cos(lat);

	double dist = sqrt(latDist*latDist + lonDist*lonDist);

	return dist*100;
}

//---------------------------Prims Algorithm---------------------------------------

std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> NetworkController::PrimsToFindMST()
{
std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> mst;
	std::unordered_map<std::string, bool> visited;
	std::unordered_map<std::string, int> key;
	std::unordered_map<std::string, std::string> parent;

	if(Links.empty())
	{
		std::cout << "No Routers Available\n";
		return mst;
	}

	for(auto &node : Links)
	{
		key[node.first] = INT_MAX;     // initialize
		visited[node.first] = false;
		parent[node.first] = "";
	}

	std::string start = Links.begin()->first;
	key[start] = 0;
	auto cmp = [](const std::pair<int, std::string>& a,const std::pair<int, std::string>& b) {
		return a.first > b.first;
	};
	std::priority_queue<std::pair<int,std::string>,std::vector<std::pair<int,std::string>>,decltype(cmp)>pq(cmp);
	pq.push({0,start});

	while(!pq.empty())
	{
		std::string u = pq.top().second;
		pq.pop();

		if(visited[u])
			continue;

		visited[u] = true;

		for(auto &nbr : Links[u])
		{
			std::string v = nbr.first;
			int weight = nbr.second;

			if(!visited[v] && weight < key[v])
			{
				key[v] = weight;
				parent[v] = u;

				pq.push({key[v], v});
			}
		}
	}

	std::cout << BOLD << MAGENTA << "\nMinimum Spanning Tree:-\n";
	std::cout<<"--------------------------"<<RESET<<std::endl;

	int totalCost = 0;

	for(auto &node : parent)
	{
		if(node.second != "")
		{
			auto it = routerdata.find(node.second);
			if(it != routerdata.end()){

				std::cout<< node.second << "(" << it->second.Location<< ")";
			}
			auto it1 = routerdata.find(node.first);
			std::cout << " ---> ";
			if(it1 != routerdata.end()){

				std::cout<< node.first << "(" << it1->second.Location<< ")";
			}

			std::cout << " Cost: ₹" << key[node.first] << std::endl;

			totalCost += key[node.first];
			mst[node.second].push_back({node.first,key[node.first]});
			mst[node.first].push_back({node.second,key[node.first]});
		}
	}

	std::cout << BOLD << ORANGE << "\nTotal MST Cost: ₹" << totalCost << RESET << std::endl;
	return mst;
}

//--------------------------------------------------------------------------------------------------

std::pair<std::vector<std::string>, int>  NetworkController::dijkstra(std::string source,std::string dest)
{
	auto cmp = [](const std::pair<int, std::string>& a,const std::pair<int, std::string>& b) {
		return a.first > b.first;
	};
	std::priority_queue<std::pair<int,std::string>,std::vector<std::pair<int,std::string>>,decltype(cmp)>pq(cmp);

	std::unordered_map<std::string,int> dist;
	std::unordered_map<std::string, std::string> parent;

	for(auto &node : Links)
	{
		dist[node.first] = INT_MAX; // Initialize distances
		parent[node.first] = "";
	}

	dist[source] = 0;

	pq.push({0,source});

	while(!pq.empty())
	{
		int cost = pq.top().first;
		std::string current = pq.top().second;
		pq.pop();

		for(auto &neighbor : Links[current])
		{
			std::string next = neighbor.first;
			int weight = neighbor.second;

			if(dist[next] > cost + weight)
			{
				dist[next] = cost + weight;
				parent[next] = current;

				pq.push({dist[next], next});
			}
		}
	}

	std::vector<std::string> path;    // Build path

	std::string node = dest;

	while(node != "")
	{
		path.push_back(node);
		node = parent[node];
	}

	reverse(path.begin(), path.end());

	return {path, dist[dest]};
}

//------------------------------------------------------------------------------------------

std::vector<std::string> NetworkController::showAllRouters()
{
	std::vector<std::string> iplist;

	int i=1;

	for(auto &x : allRouters)
	{
		std::cout<<i<<" "<< x.Location
			<<" ("<<x.IpAddr<<")\n";

		iplist.push_back(x.IpAddr);
		i++;
	}

	return iplist;
}

//--------------------------------------------------------------------------------------------

bool NetworkController::changeIP(std::string oldIP, std::string newIP)
{

	if(Links.find(newIP) != Links.end())
	{
		std::cout<<"New IP already exists\n";
		return false;
	}

	Router r = routerdata[oldIP];      // Update routerdata map
	r.IpAddr = newIP;

	routerdata.erase(oldIP);
	routerdata[newIP] = r;

	for(auto &router : allRouters)           // Update router vector
	{
		if(router.IpAddr == oldIP)
		{
			router.IpAddr = newIP;
			break;
		}
	}

	Links[newIP] = Links[oldIP];         // Move adjacency list
	Links.erase(oldIP);

	for(auto &node : Links)                       // Update neighbors
	{
		for(auto &nbr : node.second)
		{
			if(nbr.first == oldIP)
				nbr.first = newIP;
		}
	}
	return true;
}

//------------------------------------------------------------------------------------------------

std::pair<std::vector<std::string>,int> NetworkController::findAllPaths(std::string source, std::string dest)
{
	std::unordered_map<std::string,bool> visited;
	std::vector<std::string> path;
	int minCost = INT_MAX;
	std::vector<std::string> bestPath;

	std::cout << BOLD << DBLUE << "\nAll Possible Paths:-\n";
	std::cout<<"--------------------" << RESET << std::endl;

	dfsRecursive(source, dest, visited, path, 0, minCost, bestPath);
	if(!bestPath.empty())
	{
		return {bestPath, minCost};
	}
	else
	{
		std::cout<<RED<<"No Path Found!"<<RESET<<std::endl;
		return {{}, INT_MAX};
	}
}

//---------------------------------------------------------------------------------------------

void NetworkController::dfsRecursive(std::string current,  std::string dest,  std::unordered_map<std::string,bool>&visited,  std::vector<std::string> &path, int totalCost, int &minCost, std::vector<std::string> &bestPath)
{
	visited[current] = true;
	path.push_back(current);

	if(current == dest)
	{
		std::cout<<GREEN;

		for(size_t i=0;i<path.size();i++)
		{
			if(i>0){ 
			
			}
			std::cout<<path[i];
			auto it = routerdata.find(path[i]);
			if(it != routerdata.end()){

				std::cout << "("<< it->second.Location<< ")"<<RESET;
			}

			if(i!=path.size()-1)
				std::cout<<" ---> ";
		}

		std::cout<<" | Total Cost: ₹"<<totalCost<<std::endl<<std::endl;

		if(totalCost < minCost)
		{
			minCost = totalCost;
			bestPath = path;
		}
	}
	else
	{
		for(auto &neighbor : Links[current])
		{
			std::string next = neighbor.first;
			int cost = neighbor.second;

			if(!visited[next])
			{
				dfsRecursive(next, dest, visited, path, totalCost+cost, minCost, bestPath);
			}
		}
	}

	path.pop_back(); // Backtracking
	visited[current] = false;
}

//--------------------------------------------------------------------------------------------------

bool NetworkController::isvalidIp(std::string ipAddr)
{
	std::stringstream ss(ipAddr);
	std::string part;
	int count = 0;

	while (getline(ss, part, '.'))
	{
		if (part.empty()) return false;

		for(char c : part)
			if(!isdigit(c)) return false;

		int num = std::stoi(part);

		if(num < 0 || num > 255)
			return false;

		count++;
	}

	return count == 4;
}
//---------------------------------------------------------------------------------------------

void NetworkController::connectNewRouter(const Router& newRouter, int maxConnections)
{
	addRouter(newRouter);     // add router to network

	std::vector<std::pair<double, Router>> distList;

	for(const auto &r : allRouters)
	{
		if(r.IpAddr == newRouter.IpAddr)
			continue;

		double dx = newRouter.Latitude - r.Latitude;
		double dy = newRouter.Longitude - r.Longitude;

		double distance = std::sqrt(dx*dx + dy*dy);

		distList.push_back({distance, r});
	}

	std::sort(distList.begin(), distList.end(),[](const auto &a, const auto &b)
			{
				return a.first < b.first;
			});

	int connections = std::min(maxConnections, (int)distList.size());

	for(int i = 0; i < connections; i++)
	{
		addLinks(newRouter, distList[i].second);
	}

	std::cout << GREEN<< "New router connected to "<< connections<< " nearest routers\n"<< RESET;
}

//-------------------------------------------------------------------------------------
bool NetworkController::removeRouter(const std::string &ip)
{
	if(routerdata.find(ip) == routerdata.end())
	{
		std::cout<<"Router not found\n";
		return false;
	}
	Links.erase(ip);          // remove adjacency list of router

	for(auto &x : Links)      // remove this router from neighbors
	{
		auto &neighbors = x.second;

		neighbors.erase(
				std::remove_if(neighbors.begin(), neighbors.end(),
					[&](const std::pair<std::string,int> &p)
					{
					return p.first == ip;
					}),
				neighbors.end()
			       );
	}

	routerdata.erase(ip);          // remove router from map

	allRouters.erase(std::remove_if(allRouters.begin(), allRouters.end(),[&](const Router &r)
				{
					return r.IpAddr == ip;       // remove router from vector
				}),
			allRouters.end()
			);

	std::cout << "Router " << ip << " removed successfully\n";

	return true;
}


//--------------------------------------------------------------

void NetworkController::autoDetectFailure()
{
	if(allRouters.empty()) 
	{
		std::cout << "No routers available\n";       
		return;
	}

	srand(time(nullptr));

	int index = rand() % allRouters.size();

	std::string failedIP = allRouters[index].IpAddr;

	auto it = routerdata.find(failedIP);

	std::cout <<RED<< "\n⚠ Router Failure Detected\n"<<RESET;
	std::cout << failedIP << " (" << it->second.Location << ") crashed\n";

	removeRouter(failedIP);

	std::cout <<BOLD<<GREEN<< "\nNetwork topology updated\n\n"<<RESET;
}

//-------------------------------------------------------------------------------------------

void NetworkController::simulatePacketTransfer(Packet p,std::vector<std::string> path,int totalCost)
{
    std::cout<<BOLD<<GREEN<<"\n📦 Packet Simulation Started\n"<<RESET;

    std::cout<<"Source : "<<p.sourceIP<<std::endl;
    std::cout<<"Destination : "<<p.destIP<<std::endl;
    std::cout<<"Size : "<<p.size<<" bytes\n\n";

    for(size_t i=0;i<path.size();i++)
    {
        auto it = routerdata.find(path[i]);

        if(it != routerdata.end())
        {
            std::cout<<MAGENTA<<"Packet reached Router : "
                     <<path[i]
                     <<" ("<<it->second.Location<<")"
                     <<RESET<<std::endl;
        }

        if(i != path.size()-1)
            std::cout<<"Forwarding to next router...\n";
    }

    std::cout<<BOLD<<GREEN<<"\n✅ Packet Delivered\n"<<RESET;
    std::cout<<"Total Cost : "<<totalCost<<std::endl;
}

//-------------------------------------------------------------------------------

void NetworkController::generateMSTDot(std::unordered_map<std::string, std::vector<std::pair<std::string,int>>> mst)
{
    std::ofstream file("network_mst.dot");

    file<<"graph MST_Network {\n";

    file<<"layout=neato;\n";
    file<<"overlap=false;\n";
    file<<"splines=true;\n";
    file<<"bgcolor=\"white\";\n";

    file<<"node [shape=circle style=filled fillcolor=\"#A9DFBF\" color=\"#1E8449\" fontname=\"Arial\" fontsize=12 width=1.3];\n";

    file<<"edge [color=\"red\" fontname=\"Arial\" fontsize=10 penwidth=2];\n";

    for(auto &router : mst)
    {
        std::string src = router.first;

        for(auto &nbr : router.second)
        {
            std::string dest = nbr.first;
            int cost = nbr.second;

            if(src < dest)
            {
                file<<"\"SBI - "<<routerdata[src].Location<<"\" -- "
                    <<"\"SBI - "<<routerdata[dest].Location<<"\" "
                    <<"[label=\"₹"<<cost<<"\"];\n";
            }
        }
    }

    file<<"}\n";

    file.close();
}
