#include <iostream>


using namespace std;

class Ticket {
private:
	char* ticketType;
	int uniqueID;

	Ticket() : ticketType(nullptr), uniqueID(0) {}

	Ticket(const char* ticketType, int uniqueID){}


};
