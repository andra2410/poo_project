#include <iostream>
#include <string>
#include<string.h>


using namespace std;

class Ticket {
private:
	char* ticketType;
	int seatNumber;
	char* eventID;
	char* uniqueID;

public:
	Ticket() : ticketType(nullptr), seatNumber(0), uniqueID(nullptr), eventID(nullptr) {}

	Ticket(const char* ticketType, int uniqueID, const char* eventID){
	
	}

	~Ticket() {
		delete[] ticketType;
		//delete[] seatNumber;
		delete[] uniqueID;
   }

	void generateUniqueID() { //generating it based on the seat number and event id
		std::string seatStr = std::to_string(seatNumber);
		std::string eventIDStr(eventID);

		uniqueID = new char[seatStr.length() + eventID.length() + 10];
		strcpy(uniqueID, (seatStr + eventIDStr).c_str());
		
	}


};
