#include <iostream>
#include <string>
#include<string.h>


using namespace std;

class Ticket {
private:
	char* ticketType; //vip, 
	int seatNumber;
	char* eventID; //...........
	char* uniqueID;

public:
	Ticket() : ticketType(nullptr), seatNumber(0), uniqueID(nullptr), eventID(nullptr) {}

	Ticket(const char* ticketType, int seatNumber, const char* eventID){
		this->setSeatNumber(seatNumber);
		this->setEventID(eventID); 
		this->setTicketType(ticketType);
		generateUniqueID();
	}

	~Ticket() {
		delete[] ticketType;
		//delete[] seatNumber;
		delete[] uniqueID;
   }
private:

	void generateUniqueID() { //generating it based on the seat number and event id
		std::string seatStr = std::to_string(seatNumber);
		std::string eventIDStr(eventID);

		uniqueID = new char[seatStr.length() + eventIDStr.length() + 10];
		strcpy(uniqueID, (seatStr + eventIDStr).c_str());
		
	}

public:
	//getters ; tickettype, seatno, event id, uniqueid

	const char* getTicketType() const {
		return ticketType;
	}

	const char* getEventId() const {
		return eventID;
	}

	const char* getUniqueID() const {
		return uniqueID;
	}

	int getSeatNumber() const {
		return seatNumber;
	}

	//setters : tickettype, seatno, event id, unique id

	void setTicketType(const char* tType) {
		delete[] ticketType;
		ticketType = new char[strlen(tType) + 1];
		strcpy(ticketType, tType);
	}

	void setSeatNumber(int seat) {
		seatNumber = seat;
	}

	void setEventID(const char* event) {
		delete[] eventID;
		eventID = new char[strlen(event) + 1];
		strcpy(eventID, event);
	}



};
