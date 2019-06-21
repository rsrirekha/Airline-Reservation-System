#pragma once
#include<string> 

using namespace std;
namespace FlightReservationSystem
{

	class PassengerInfo
	{
	public: 

		PassengerInfo() = default;
		PassengerInfo(const std::string& flightNo, const std::string& seatNo, const std::string& FName, const std::string& LName, const std::string& passport, long ccNo);

		const string& getFirstName() const;
		void setFirstName(const string& FName);

		const string& getLastName() const;
		void setLastName(const string& LName);
		
		const string& getPassportNo() const;
		void setPassportNo(const string& passport);

		const string& getSeatNo() const;
		void setSeatNo(const string& seat);

		const string& getFlightNo() const;
		void setFlightNo(const string& flight);

		long getCreditCardNo() const;
		void setCreditCardNo(long card);

		int getTicketNo() const;
		void setTicketNo(int ticket);

		bool getValidTicket() const;
		void setValidTicket(bool valid);

	private:

		string mFirstName;
		string mLastName;
		string mPassportNo;

		string mSeatNo;
		string mFlightNo;

		long mCreditCardNo=0;
		int mTicketNo=0;

		bool mValidTicket = true;
	};
}

