//EVENT LOCATION CLASS
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

    const static string COMPANY_NAME;

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
    //copy const
    EventLocation(const EventLocation& other) {
        this->setLocationDetails(new string(*other.locationDetails));
        this->setSeatInformation(new int[other.maxSeats]);
        std::copy(other.seatInformation, other.seatInformation + other.maxSeats, this->seatInformation);
        this->setMaxSeats(other.maxSeats);
    }

    EventLocation& operator=(const EventLocation& other) {
        if (this != &other) {
            this->setLocationDetails(new string(*other.locationDetails));
            this->setSeatInformation(new int[other.maxSeats]);
            std::copy(other.seatInformation, other.seatInformation + other.maxSeats, this->seatInformation);
            this->setMaxSeats(other.maxSeats);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const EventLocation& eventLocation) {
        os << "Location: " << *eventLocation.locationDetails;
        eventLocation.printSeatInformation();
        return os;
    }

    bool operator!() const {
        // Check if the location has no details
        return locationDetails == nullptr || locationDetails->empty();
    }

    bool operator==(const EventLocation& other) const {
        // Compare location details and max seats
        return *locationDetails == *other.locationDetails && maxSeats == other.maxSeats;
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
private:

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
        cout << "Seat info: ";
        for (int i = 0; i < maxSeats; i++) cout << seatInformation[i] << " ";
    }

public:
    //generic methods
    void processLocation() {
       
        cout << "Processing Location: " << *this->locationDetails <<endl;
    }

    void displayLocationInfo() const {
        cout << "Location: " << *this->locationDetails << endl;
        printSeatInformation();
    }


};