#include "Network.h"   // userdefined headerfiles
#include "Router.h"
#include "RouterFactory.h"

#include <iostream>
#include <limits>  // predefined headerfiles
#include <sstream>
#include<vector> 
#include<unordered_map>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define MAGENTA  "\033[35m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define PURPLE   "\033[34m"
#define BROWN   "\033[33m"  
#define YELLOW  "\033[93m"
#define DBLUE    "\033[96m"
#define LBLUE    "\033[36m"
#define ORANGE "\033[38;5;208m"

int main()
{
	RouterFactory factory;
	NetworkController network(10);

	int choice;
	std::vector<Router> router = factory.createRouter();
	std::unordered_map<std::string, std::vector<std::pair<std::string,int>>>mst;

	network.loadRouters(router);
	std::cout << BOLD << LBLUE << "SBI Branches available in Hyderabad:-\n"<< RESET;
	network.showAllRouters();

	network.connectAllRouters();

	while(true)
	{
		std::cout << BOLD << YELLOW << "\n===== NETWORK ROUTING SYSTEM =====\n" << RESET;

		std::cout << "1) Display All connected routers \n";
		std::cout << "2) Find the Optimal Path\n";
		std::cout << "3) Shortest Path\n";
		std::cout << "4) Change Router IP\n";
		std::cout << "5) Add new Location\n";
		std::cout << "6) Check Router Failure \n";
		std::cout << "7) Visualize Graph\n";
		std::cout << "8) Exit\n";

		std::cout <<BOLD << DBLUE <<"\nEnter Choice: " << RESET;
		std::cin >> choice;

		switch(choice)
		{

			case 1:
				{
					network.DisplayRoutes();
					break;
				}

			case 2:
				{
					mst=network.PrimsToFindMST();
					break;
				}

			case 3:
				{
					auto iplist = network.showAllRouters();

					size_t srcChoice, destChoice;

					std::cout << MAGENTA << "Select Source Index: " << RESET;
					std::cin >> srcChoice;

					std::cout << MAGENTA << "Select Destination Index: " << RESET;
					std::cin >> destChoice;

					if(srcChoice < 1 || destChoice < 1 ||srcChoice > iplist.size() ||destChoice > iplist.size())
					{
						std::cout << RED << "Invalid Selection\n" << RESET;
						break;
					}

					std::string source = iplist[srcChoice-1];
					std::string destination = iplist[destChoice-1];
					auto Graph = network.findAllPaths(source,destination);
					auto result = network.dijkstra(source,destination);

					std::cout << BOLD << RED << "\nShortest Path:-\n" << RESET;
					if(Graph.second < result.second){
						for(size_t i=0;i<Graph.first.size();i++)
						{
							std::cout << DBLUE <<Graph.first[i];

							if(i != Graph.first.size()-1)
								std::cout << " ---> ";
						}
						std::cout << BOLD << "\nTotal Cost: ₹" << Graph.second << RESET << std::endl;
					}
					else{

						for(size_t i=0;i<result.first.size();i++)
						{
							std::cout << DBLUE << result.first[i];

							if(i != result.first.size()-1)
								std::cout << " ---> ";
						}

						std::cout << BOLD << "\nTotal Cost: ₹" << result.second << RESET<< std::endl;
					}
				Packet p;
				p.sourceIP=source;
				p.destIP=destination;
				p.size=512;
				network.simulatePacketTransfer(p,result.first,result.second);   ///packet,path,cost
				break;
				
				}

			case 4:
				{
					std::string oldIP,newIP;

					ip:
					std::cout << DBLUE << "Enter Old IP: "<<RESET;
					std::cin >> oldIP;
					if( !network.findOldIP(oldIP) ){
						std::cout<<BOLD<<RED<<"Old IP Address not available!!!" << std::endl<<RESET;
						goto ip;
					}
						l1:
					std::cout << DBLUE << "Enter New IP: "<<RESET;
					std::cin >> newIP;
					if(!network.isvalidIp(newIP))
					{
						std::cout<<BOLD<<RED<<"IP Address not valid!!!" << std::endl<<RESET;
						goto l1;
					}

					if(network.changeIP(oldIP,newIP))
						std::cout << GREEN << "IP Updated Successfully\n" << RESET;
					else
						std::cout << BOLD << RED << "IP Update Failed\n" << RESET;

					break;
				}

			case 5:
				{
					factory.showAvailableLocations();

					std::string name, ip;
					double lat, lon;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\nEnter new location name: "<<std::endl;
					std::getline(std::cin, name);
					l:
					std::cout << "Enter IP address: "<<std::endl;
					std::getline(std::cin, ip);

					if(!network.isvalidIp(ip))
					{
						std::cout<<BOLD<<RED<<"IP Address not valid!!!" << std::endl<<RESET;
						goto l;
					}
					std::cout << "Enter Latitude : ";
					std::cin >> lat;

					std::cout << "Enter Longitude: ";
					std::cin >> lon;

					Router r=factory.addNewLocation(name, ip, lat, lon);
					std::cout << "\nUpdated Locations:\n";
					factory.showAvailableLocations();
					network.connectNewRouter(r,3);
					break;
				} 
			case 6:
				{
					network.autoDetectFailure();
					network.showAllRouters();
					break;
				}

			case 7:
				{
					network.generateDotFile();
					system("dot -Tpng network.dot -o network.png");
					system("xdg-open network.png");
					network.generateMSTDot(mst);
    					system("dot -Tpng network_mst.dot -o network_mst.png");
    					system("xdg-open network_mst.png");
					break;
				}

			case 8:
				{
					std::cout << LBLUE << "Exiting System...\n" << RESET;
					return 0;
				}

			default:
				{
					std::cout << RED << "Invalid Choice\n" << RESET;
				}

		}
	}

	return 0;
}
