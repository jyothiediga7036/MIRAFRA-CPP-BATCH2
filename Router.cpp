#include "Router.h"

Router::Router()
{
}

Router::Router(double lat, double lon, std::string loc, std::string ip)
{
	Latitude = lat;
	Longitude = lon;
	Location = loc;
	IpAddr = ip;
	isActive = true;  
}
