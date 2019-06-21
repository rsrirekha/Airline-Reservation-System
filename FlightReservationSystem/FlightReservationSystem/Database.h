#pragma once
#include "FlightInfo.h"
#include "PassengerInfo.h"
#include <vector>


using namespace std;

namespace FlightReservationSystem {
	const int kDefaultTicketNo = 1000;
	class Database
	{
	public:
		vector<FlightInfo> getFlightSchedule() ;
		FlightInfo getFlightSchedule(string flightCode) const;
		PassengerInfo& IssueTicket(const std::string& flightNo, const std::string& seatNo,const std::string& FName,
			const std::string& LName, const std::string& passport, long ccNo);
		vector<PassengerInfo> getAllTickets();
		void deleteTicket(int ticketNo);
		vector<PassengerInfo> getAllDeletedTickets() const;
		vector<PassengerInfo> getPassengerList(string flightCode) const;

	private:

		int mNextTicketNumber = kDefaultTicketNo;
		vector<FlightInfo>mFlightSchedule; 
		vector<PassengerInfo>mPassengerList;
	};
}

