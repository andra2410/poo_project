#include <iostream>
#include "EventLocation.h"
#include <string>
using namespace std;


using namespace std;

class EventLocation {
private:
    string* locationDetails;  
    int* seatInformation; 
    int maxSeats;

public:
    // constructor, deconstructor, getters, setters

    EventLocation() : locationDetails(nullptr), seatInformation(0), maxSeats(0) {}

    EventLocation(const string& location, int* seatInfo, int max) {
        this->setLocationDetails(new string(location));
        this->setSeatInformation(seatInfo);
        this->setMaxSeats(max);
    }

    ~EventLocation() {
        delete locationDetails;
        delete[] seatInformation;
      
    }

    // getters

    const string* getLocationDetails() const {
        return this->locationDetails;
   }

    int* getSeatInformation() const {
        return this->seatInformation;
    }

    const int getMaxSeats() const {
        return this->maxSeats;
    }

    // setters

    void setLocationDetails(const string* location) {
        delete[] this->locationDetails;
        this->locationDetails = new string(*location);
    }

    void setMaxSeats(int seats) {
        if (seats < 0) {
            throw invalid_argument("Number of seats cannot be negative");
        }
        this->maxSeats = seats;
    }

    void setSeatInformation(int* seatinfo) {
        this->seatInformation = seatinfo;
    }

    void printSeatInformation() const {
        cout << "Seat info";
        for (int i = 0; i < maxSeats; i++) cout << seatInformation[i] << " ";
    }
};