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

    EventLocation(string* locationDetails, int* seatInformation, int maxSeats) {
        this->setLocationDetails(locationDetails);
        this->setSeatInformation(seatInformation);
        this->setMaxSeats(maxSeats);
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
        this->maxSeats = seats;
    }

    void setSeatInformation(int* seatinfo) {
        this->seatInformation = seatinfo;
    }
};