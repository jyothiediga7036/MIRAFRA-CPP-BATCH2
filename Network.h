#ifndef NETWORK_H
#define NETWORK_H

#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Router.h"
#include <sstream>
struct Packet
{
    std::string sourceIP;
    std::string destIP;
    int size;
};


class NetworkController
{
	private:

		int RouterSize;

		std::unordered_map<std::string,std::vector<std::pair<std::string,int>>> Links;

		std::vector<Router> allRouters;

		int costEstimation(const Router& r1,const Router& r2);

	public:

		std::unordered_map<std::string, Router> routerdata;

		NetworkController(int size);

		~NetworkController();
		void loadRouters(std::vector<Router> &r);

		void addRouter(const Router& r);

		void addLinks(const Router& r1,const Router& r2);

		void connectAllRouters();

		void DisplayRoutes();
		bool isvalidIp(std::string ipAddr);

		bool changeIP(std::string oldIP, std::string newIP);
		bool findOldIP(std::string oldIP);

		bool removeRouter(const std::string &ip);
		
		void autoDetectFailure();
		std::vector<std::string> showAllRouters();
		void connectNewRouter(const Router& newRouter, int maxConnections);

		std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> PrimsToFindMST();

		std::pair<std::vector<std::string>,int> dijkstra(std::string source,std::string dest);

		std::pair<std::vector<std::string>,int> findAllPaths(std::string source,std::string dest);

		void dfsRecursive(std::string current,std::string dest,
				std::unordered_map<std::string,bool>& visited,
				std::vector<std::string>& path,
				int totalCost,
				int& minCost,
				std::vector<std::string>& bestPath);
		
		void generateDotFile();
		void simulatePacketTransfer(Packet,std::vector<std::string>,int);
		void generateMSTDot(std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> mst);
};

#endif
