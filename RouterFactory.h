#ifndef ROUTERFACTORY_H
#define ROUTERFACTORY_H

#include "Router.h"
#include <unordered_map>
#include <tuple>
#include <string>
#include <optional>
#include<vector>

class RouterFactory
{
	private:
		std::unordered_map<std::string, std::tuple<std::string,double,double>> locationDetails; 
		//location --> IP Addr, latitude, longitude.

	public:
		RouterFactory();

		//bool locationExists(std::string loc);

		std::vector<Router> createRouter();

		void showAvailableLocations();

		Router addNewLocation(std::string loc, std::string ip, double lat, double lon);
};

#endif
