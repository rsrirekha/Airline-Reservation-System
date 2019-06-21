#include "pch.h"
#include "FlightInfo.h"

using namespace std;

namespace FlightReservationSystem {

	FlightInfo::FlightInfo(const std::string& flightCode, const std::string& DAirport, const std::string& AAirport, const std::string& DoD, const std::string& DoA,int cost, int avail)
		: mFlightCode(flightCode),mDepartureAirport(DAirport),mArrivalAirport(AAirport),mDepartureDate(DoD),mArrivalDate(DoA),mTicketCost(cost),mAvailability(avail){}
	
	const string& FlightInfo::getDepartureAirport() const
	{
		return mDepartureAirport;
	}
	
	void FlightInfo::setDepartureAirport(const string& departureAirport) 
	{	
		mDepartureAirport = departureAirport;
	}

	const string& FlightInfo::getArrivalAirport() const
	{
		return mArrivalAirport;
	}
	void FlightInfo::setArrivalAirport(const string& arrivalAirport)
	{
		mArrivalAirport = arrivalAirport;
	}

	void FlightInfo::setDepartureDate(const string& dDate)
	{
		mDepartureDate = dDate;
	}

	const string& FlightInfo::getDepartureDate() const
	{
		return mDepartureDate;
	}

	void FlightInfo::setArrivalDate(const string& aDate)
	{	
		mArrivalDate = aDate;
	}
	const string& FlightInfo::getArrivalDate() const
	{
		return mArrivalDate;
	}

	void FlightInfo::setFlightCode(const string& flightCode)
	{
		mFlightCode= flightCode;
	}
	const string& FlightInfo::getFlightCode() const
	{
		return mFlightCode;
	}
	void FlightInfo::setAvailability(int availability)
	{
		mAvailability = availability;
	}
	 int FlightInfo::getAvailability() const
	{
		return mAvailability;
	} 
	 void FlightInfo::setTicketCost(int cost)
	 {
		 mTicketCost = cost;
	 }
	 int FlightInfo::getTicketCost() const
	 {
		 return mTicketCost;
	 }
	 void FlightInfo::setSeats(const vector<string> seats)
	 {
		 mSeats = seats;

	 }
	 vector<string> FlightInfo::getSeats() const
	 {
		 return mSeats;
	 }

}