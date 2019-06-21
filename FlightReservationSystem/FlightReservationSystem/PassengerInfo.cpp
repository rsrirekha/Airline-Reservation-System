#include "pch.h"
#include "PassengerInfo.h"

namespace FlightReservationSystem 
{

	PassengerInfo::PassengerInfo(const std::string& flightNo, const std::string& seatNo, 
		const std::string& FName, const std::string& LName,
		const std::string& passport, long ccNo):
		mFlightNo(flightNo),mSeatNo(seatNo),
		mFirstName(FName),mLastName(LName),
		mPassportNo(passport),mCreditCardNo(ccNo){}

	const string& PassengerInfo::getFirstName() const
	{
		return mFirstName;
	}
	void PassengerInfo::setFirstName(const string& FName)
	{
		mFirstName = FName;
	}
	const string& PassengerInfo::getLastName() const
	{
		return mLastName;
	}
	void PassengerInfo::setLastName(const string& LName)
	{
		mLastName = LName;
	}
	const string& PassengerInfo::getPassportNo() const
	{
		return mPassportNo;
	}
	void PassengerInfo::setPassportNo(const string& passport)
	{
		mPassportNo = passport;
	}
	
	const string& PassengerInfo::getSeatNo() const
	{
		return mSeatNo;
	}
	void PassengerInfo::setSeatNo(const string& seat)
	{
		mSeatNo = seat;
	}
	const string& PassengerInfo::getFlightNo() const
	{
		return mFlightNo;
	}
	void PassengerInfo::setFlightNo(const string& flight)
	{
		mFlightNo = flight;
	}
	void PassengerInfo::setCreditCardNo(long card)
	{
		mCreditCardNo = card;
	}
	long PassengerInfo::getCreditCardNo() const
	{
		return mCreditCardNo;
	}
	void PassengerInfo::setTicketNo(int ticketNo)
	{
		mTicketNo = ticketNo;
	}
	int PassengerInfo::getTicketNo() const
	{
		return mTicketNo;
	}

	bool PassengerInfo::getValidTicket() const {
		return mValidTicket;
	}
	void PassengerInfo::setValidTicket(bool valid) {
		mValidTicket = valid;
	}

}