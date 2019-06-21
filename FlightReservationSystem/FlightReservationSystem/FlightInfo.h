#pragma once
#include <string>
#include <vector>

using namespace std;
namespace FlightReservationSystem {


	class FlightInfo
	{
	public:
		FlightInfo() = default;
		FlightInfo(const std::string& flightCode, const std::string& DAirport, const std::string& AAirport, const std::string& DoD, const std::string& AoD,int ticketCost, int avail);


	
	//Getters and setters
	void setDepartureAirport(const string& dAirport);
	const string& getDepartureAirport() const;

	void setArrivalAirport(const string& aAirport);
	const string& getArrivalAirport() const;

	void setDepartureDate(const string& DDate);
	const string& getDepartureDate() const;

	void setArrivalDate(const string& ADate);
	const string& getArrivalDate() const;

	void setAvailability(int avail);
	 int getAvailability() const;

	void setFlightCode(const string& flightCode);
	const string& getFlightCode() const;


	void setTicketCost(int cost);
	int getTicketCost() const;

	void setSeats(const vector<string> seats);
	vector<string> getSeats() const;

private:
	string mFlightCode;
	string mDepartureAirport;
	string mArrivalAirport;
	string mDepartureDate;
	string mArrivalDate;
	
	vector<string> mSeats = {"A1","A2","B1","B2"};

	int mAvailability = -1;
	int mTicketCost=1000;
	
};

}

