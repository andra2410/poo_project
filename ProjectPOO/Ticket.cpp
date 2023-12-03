#include <iostream>
#include <string>
#include<string.h>


using namespace std;

class Ticket {
private:
	char* ticketType; //vip, 
	int seatNumber;
	char* eventID;
	char* uniqueID;
	double* ticketPrices; // Dynamic numeric vector for prices

public:
	
	Ticket() : ticketPrices(0), ticketType(nullptr), seatNumber(0), uniqueID(nullptr), eventID(nullptr) {}

	Ticket(const char* ticketType, int seatNumber, const char* eventID, double* prices){
		this->setSeatNumber(seatNumber);
		this->setEventID(eventID); 
		this->setTicketType(ticketType);
		this->setTicketPrices(prices);
		generateUniqueID();
	}

	~Ticket() {
		delete[] ticketType;
		//delete[] seatNumber;
		delete[] uniqueID;
		delete[] ticketPrices;
   }
private:

	void generateUniqueID() {
		std::string seatStr = std::to_string(seatNumber);
		std::string eventIDStr(eventID);

		// Calculate the total length, including null terminators
		size_t totalLength = seatStr.length() + eventIDStr.length() + 1;

		uniqueID = new char[totalLength];

		// Use strcpy_s to prevent buffer overflow
		strcpy_s(uniqueID, totalLength, seatStr.c_str());

		// Use strcat_s to concatenate eventIDStr
		strcat_s(uniqueID, totalLength, eventIDStr.c_str());
	}
public:
	//static vb
	const static int MAX_TICKET_TYPES = 5;
	static double TAX_RATE; 

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

	const double* getTicketPrices() const {
		return ticketPrices;
	}

	//setters : tickettype, seatno, event id, unique id

	void setTicketType(const char* tType) {
		delete[] ticketType;
		ticketType = new char[strlen(tType) + 1];
		strcpy_s(this->ticketType, strlen(tType), tType);
	}

	void setSeatNumber(int seat) {
		if (seat < 0) {
			throw invalid_argument("Seat number cannot be negative");
	   }
		seatNumber = seat;
	}

	void setEventID(const char* event) {
		delete[] eventID;
		this->eventID = new char[strlen(event) + 1];
		strcpy_s(this->eventID, strlen(event), event);
	}

	void setTicketPrices(double* prices) {
		delete[] ticketPrices;
		ticketPrices = new double[MAX_TICKET_TYPES];
		for (int i = 0; i < MAX_TICKET_TYPES; ++i) {
			ticketPrices[i] = prices[i];
		}
	}



};
