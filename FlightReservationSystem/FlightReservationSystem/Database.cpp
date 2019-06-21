#include "pch.h"
#include "Database.h"
#include "FlightInfo.h"
#include "PassengerInfo.h"

#include <iostream>
#include <fstream>
#include <string>
#include<vector>

namespace FlightReservationSystem {


	vector<FlightInfo> Database::getFlightSchedule() 
	{
		ifstream myfile("FlightInfo.txt");
		
		string flightCode;
		string departAirport;
		string arrivalAirport;
		string DoD;
		string DoA;
		string ticketCost;
		string avail;
		if (mFlightSchedule.empty()) {
			while (!myfile.eof())
			{
				getline(myfile, flightCode, ',');
				getline(myfile, departAirport, ',');
				getline(myfile, arrivalAirport, ',');
				getline(myfile, DoD, ',');
				getline(myfile, DoA, ',');
				getline(myfile, ticketCost, ',');
				getline(myfile, avail, '\n');

				FlightInfo flight(flightCode, departAirport, arrivalAirport, DoD, DoA, stoi(ticketCost), stoi(avail));

				mFlightSchedule.push_back(flight);

			}
		}
		return mFlightSchedule;
	}

	FlightInfo Database::getFlightSchedule(string flightCode) const
	{		
		for(auto& flightSchedule:mFlightSchedule)
		{
			if (flightSchedule.getFlightCode()==flightCode) {
				return flightSchedule;
			}
		}
		throw logic_error("No Flight found.");
	}

	PassengerInfo& Database::IssueTicket(const std::string& flightNo, const std::string& seatNo, const std::string& FName, const std::string& LName, const std::string& passport, long ccNo)
	{
		PassengerInfo Passenger(flightNo, seatNo, FName, LName, passport, ccNo);
		Passenger.setTicketNo(mNextTicketNumber++);
		mPassengerList.push_back(Passenger);
		for (FlightInfo& flight : mFlightSchedule) {
			if (flight.getFlightCode() == flightNo) {

				//availabilty -1
				flight.setAvailability(flight.getAvailability() - 1);
				vector<string> seat = flight.getSeats();
				for (auto i = seat.begin(); i != seat.end(); ++i) {
					if (*i == seatNo) {
						seat.erase(i);
						
						break;
					}
				}
				flight.setSeats(seat);
				break;
			}
			
		}
		return  mPassengerList[mPassengerList.size() - 1];
	}

	vector<PassengerInfo> Database::getAllTickets()
	{
		vector<PassengerInfo> passengerList;
		for (PassengerInfo passenger : mPassengerList) {
			if (passenger.getValidTicket()) {
				passengerList.push_back(passenger);
			}
		}
		return passengerList;
	}

	void Database::deleteTicket(int ticketNo)
	{
		string flightCode; 
		string seatNo;
		for (auto& passenger : mPassengerList)
		{
			if (passenger.getTicketNo() == ticketNo) {
				passenger.setValidTicket(false);
				flightCode = passenger.getFlightNo();
				seatNo = passenger.getSeatNo();
				break;
			}
		}
		for (auto& flight : mFlightSchedule) 
		{
			if (flight.getFlightCode()==flightCode) {
				flight.setAvailability(flight.getAvailability()+1);
				vector<string> seat = flight.getSeats();
				seat.push_back(seatNo);
				flight.setSeats(seat);
			}
		}


	}
	vector<PassengerInfo> Database::getAllDeletedTickets() const
	{
		vector<PassengerInfo> passengerList;
		for (PassengerInfo passenger : mPassengerList) {
			if (!passenger.getValidTicket()) {
				passengerList.push_back(passenger);
			}
		}
		return passengerList;
	}

	vector<PassengerInfo> Database::getPassengerList(string flightCode) const
	{
		vector<PassengerInfo> passengerList;
		for (PassengerInfo passenger:mPassengerList) {
			if (passenger.getFlightNo() == flightCode && passenger.getValidTicket()==true) {
				passengerList.push_back(passenger);
			}
		}
		return passengerList;
	}
}