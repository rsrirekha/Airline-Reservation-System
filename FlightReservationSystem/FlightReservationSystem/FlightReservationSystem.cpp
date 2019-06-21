// FlightReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Database.h"

using namespace std;
using namespace FlightReservationSystem;


int displayMenu();
void getAllFlightSchedule(Database& db);
void getFlightSchedule(Database& db);
void IssueTicket(Database& db);
void listAllTickets(Database& db);
void displayPassenger(PassengerInfo& passenger);
void voidTicket(Database& db);
void getAllVoidTickets(Database& db);

int main()
{
	Database data;
	
	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			getAllFlightSchedule(data);
			break;
		case 2:
			IssueTicket(data);
			break;		
		case 3:
			getFlightSchedule(data);
			break;
		case 4:
			listAllTickets(data);
			break;
		case 5: 
			voidTicket(data);
			break;
		case 6:
			getAllVoidTickets(data);
			break;
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}
	
	return 0;
}

int displayMenu()
{
	
	int selection;

	cout << endl;
	cout << "Airline Reservation System" << endl;
	cout << "---------------------------" << endl;
	cout << "1) All Flight Information" << endl;
	cout << "2) Issue Ticket " << endl;
	cout << "3) Flight Information" << endl;
	cout << "4) List All Valid Tickets" << endl;
	cout << "5) Void Ticket" << endl;
	cout << "6) List All Void Tickets" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "Input Selection :  ";

	cin >> selection;

	return selection;
}


void getAllFlightSchedule(Database& db) {

	vector<FlightInfo> flightVector = db.getFlightSchedule();
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << " Code " << "\t" << " Departure " << "\t" << " Arrival " << "\t" << " DoD " << "\t" << " DoA " << "\t" <<"Cost"<<"\t" <<" Availability " << "\n";
	cout << "-------------------------------------------------------------------------------------------------------\n";
		for (auto& flight : flightVector)
	{ 
			cout << flight.getFlightCode() << "\t";
			cout << flight.getDepartureAirport() << "\t";
			cout << flight.getArrivalAirport() << "\t";
			cout << flight.getDepartureDate() << "\t";
			cout << flight.getArrivalDate() << "\t";
			cout << flight.getTicketCost() << "\t";
			cout << flight.getAvailability() << "\n";
	}
}
	void getFlightSchedule(Database& db)
	{
		string flightCode;
		cout << "Enter the flightcode:";
		cin >> flightCode;
		try {
			FlightInfo flight = db.getFlightSchedule(flightCode);
			cout << "-----------------------------------------------------------------------------------------------------\n";
			cout << " Code " << "\t" << " Departure " << "\t" << " Arrival " << "\t" << " DoD " << "\t" << " DoA " << "\t" << "Cost" << "\t" << " Availability " << "seats"<<"\n";
			cout << "-------------------------------------------------------------------------------------------------------\n";
			cout << flight.getFlightCode() << "\t";
			cout << flight.getDepartureAirport() << "\t";
			cout << flight.getArrivalAirport() << "\t";
			cout << flight.getDepartureDate() << "\t";
			cout << flight.getArrivalDate() << "\t";
			cout << flight.getTicketCost() << "\t";
			cout << flight.getAvailability() << "\t";
			for (string seat : flight.getSeats()) {
				cout << seat.c_str() << ",";
			}
			cout << endl;

			vector<PassengerInfo> passengerList = db.getPassengerList(flightCode);
			cout << "------------------------------------------------------------" << endl;
			cout << "TicketNo" << "\t"<<"Passport"<<"\t" << "Name" << "\t" << "seat no" << "\t" << endl;
			cout << "--------------------------------------------------------------" << endl;
			for (PassengerInfo passenger : passengerList) {
				cout <<passenger.getTicketNo()  << "\t";
				cout <<passenger.getPassportNo()  << "\t";
				cout << passenger.getFirstName()<<" "<<passenger.getLastName() << "\t";
				cout << passenger.getSeatNo() << "\n";
			}
		}
		catch (const std::logic_error& exception) {
			cout << "ERROR: Invalid FlightCode : "<< exception.what() <<endl;
		}
		
	}

	

	void IssueTicket(Database& db)
	{
		string fligtNo;
		string FName;
		string LName;
		string seatNo;
		string passport;

		long card;

		cout << "Issue Ticket"<<endl;
		cout << "------------------------------------------------"<<endl;
		cout << "Enter FlightNo :";
		cin >> fligtNo;
		try {
			FlightInfo flight = db.getFlightSchedule(fligtNo);
			if ((flight.getSeats().empty())) {
				throw logic_error("No Seats Available");
			}
			cout << "Seats Available :";
			for (auto& seat : flight.getSeats()) {
				cout << seat << ",";
			}
			cout << "\n";
			cout << "Enter SeatNo :";
			cin >> seatNo;
			cout << "Enter First Name :";
			cin >> FName;
			cout << "Enter Last Name:";
			cin >> LName;
			cout << "Enter PassportNo:";
			cin >> passport;
			cout << "Enter CreditCardNo:";
			cin >> card;
			db.IssueTicket(fligtNo, seatNo, FName, LName, passport, card);		
		}
		catch(const std::logic_error& exception){
			cout << "ERROR: Invalid FlightCode : " << exception.what() << endl;
		}
	}

	void listAllTickets(Database& db)
	{
		cout << "------------------------------------------------------------"<<endl;
		cout << "TicketNo" << "\t" << "Name" << "\t" << "flight No" << "\t" << "seat no" << "\t"<<endl;
		cout << "--------------------------------------------------------------"<<endl;
		vector<PassengerInfo> passengerList = db.getAllTickets();
		for (auto& passenger : passengerList) {
			displayPassenger(passenger);
		}

	}
	void displayPassenger(PassengerInfo& passenger) {
		cout << passenger.getTicketNo() << "\t";
		cout << passenger.getFirstName()<< " "<<passenger.getLastName() << "\t";
		cout << passenger.getFlightNo() << "\t";
		cout << passenger.getSeatNo() << "\n";
	}

	void voidTicket(Database& db) {
		string ticketno;
		cout << "Enter TicketNo:";
		cin >> ticketno;
		db.deleteTicket(stoi(ticketno));
	}

	void getAllVoidTickets(Database& db) {

		cout << "------------------------------------------------------------" << endl;
		cout << "TicketNo" << "\t" << "Name" << "\t" << "flight No" << "\t" << "seat no" << "\t" << endl;
		cout << "--------------------------------------------------------------" << endl;
		vector<PassengerInfo> passengerList = db.getAllDeletedTickets();
		for (auto& passenger : passengerList) {
			displayPassenger(passenger);
		}
	}