#ifndef ROUTER_H
#define ROUTER_H

#include <string>

class Router
{
	public:
		double Latitude;
		double Longitude;
		std::string Location;
		std::string IpAddr;
		bool isActive = true;   
		Router();
		Router(double lat, double lon, std::string loc, std::string ip);
};

#endif
