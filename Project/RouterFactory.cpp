#include "RouterFactory.h"
#include <iostream>
#include <algorithm>
#include <optional>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define ORANGE "\033[38;5;208m"

RouterFactory::RouterFactory()
{
	locationDetails["SBI - Kondapur"] = {"192.168.1.1", 17.455309, 78.364342};
	locationDetails["SBI - HiTech City"] = {"192.168.1.2", 17.450812, 78.380935};
	locationDetails["SBI - Financial District"] = {"192.168.2.1", 17.422670, 78.347638};
	locationDetails["SBI - Gachibowli"] = {"192.168.2.2", 17.462709, 78.350648};
	locationDetails["SBI - Kukatpally"] = {"192.168.10.1", 17.490841, 78.392876};
	locationDetails["SBI - Madhapur"] = {"192.168.2.7", 17.438741, 78.396064};
	locationDetails["SBI - Jubliee Hills"] = {"192.168.3.1", 17.439817, 78.399133};
	locationDetails["SBI - Miyapur"] = {"192.168.4.5", 17.495826, 78.355689};
	locationDetails["SBI - Manikonda"] = {"192.168.3.9", 17.442068, 78.360228};
	locationDetails["SBI - GayatriNagar"] = {"192.168.10.5", 17.458649, 78.402548};
}

std::vector<Router> RouterFactory::createRouter()
{
    std::vector<Router> routers;

    for(auto &x : locationDetails)
    {
        Router r(
            std::get<1>(x.second),
            std::get<2>(x.second),
            x.first,
            std::get<0>(x.second)
        );

        routers.push_back(r);
    }

    return routers;
}

//-------------------------------------------------------------------------------------------------

void RouterFactory::showAvailableLocations()
{
	std::cout << BOLD << GREEN << "\nAvailable Locations: \n";
	std::cout<< "---------------------" << RESET<<std::endl;

	for(auto &x : locationDetails) //
	{
		std::cout<<BOLD<<MAGENTA<<x.first<<RESET<<std::endl;
	}
}
//------------------------------------------------------------------------------------

Router RouterFactory::addNewLocation(std::string loc,std::string ip,double lat,double lon)
{
    if(lat < -90 || lat > 90)
    {
        std::cout << RED << "Invalid Latitude!" << RESET << std::endl;
        throw std::invalid_argument("Invalid longitude");
    }

    if(lon < -180 || lon > 180)
    {
        std::cout << RED << "Invalid Longitude!" << RESET << std::endl;
        throw std::invalid_argument("Invalid longitude");
    }

    locationDetails[loc] = {ip, lat, lon};

    Router r(lat, lon, loc, ip);

    std::cout << GREEN << "New location added successfully!" << RESET << std::endl;

     return Router(lat, lon, loc, ip);
}
