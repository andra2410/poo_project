#include <iostream>
using namespace std;

class Event {
private:
    char* eventDetails;
    char* eventDate;
    char* eventTime;
    //EventLocation eventlocation;
    int maxTickets;
    //bool doesItExist;

public:
    Event() : eventDetails(nullptr), eventDate(nullptr), eventTime(nullptr), maxTickets(0) {}
        
    

    Event(const char* eventDetails, const char* eventDate, const char* eventTime, int maxTickets) {
        this->setEventDetails(eventDetails);
        this->setEventDate(eventDate);
        this->setEventTime(eventTime);
        this->setMaxTickets(maxTickets);
       

    }

    // Copy Constructor
    Event(const Event& other) {
        this->setEventDetails(other.eventDetails);
        this->setEventDate(other.eventDate);
        this->setEventTime(other.eventTime);
        this->setMaxTickets(other.maxTickets);
    }


    //destructor
    ~Event() {
        delete[] eventDetails;
        delete[] eventDate;
        delete[] eventTime;
    }

    //= operator
    Event& operator=(const Event& other) {
        if (this != &other) {
            this->setEventDetails(other.eventDetails);
            this->setEventDate(other.eventDate);
            this->setEventTime(other.eventTime);
            this->setMaxTickets(other.maxTickets);
        }
        return *this;
    }
    // Overload << Operator 
    friend ostream& operator<<(ostream& os, const Event& event) {
        os << "Event Details: " << event.eventDetails << "\nDate: " << event.eventDate
            << "\nTime: " << event.eventTime << "\nMax Tickets: " << event.maxTickets;
        return os;
    }

    Event operator+(const Event& other) const {
        // Combine event details, date, and time
        char* combinedDetails = new char[strlen(eventDetails) + strlen(other.eventDetails) + 1];
        strcpy_s(combinedDetails, strlen(eventDetails) + 1, eventDetails);
        strcat_s(combinedDetails, strlen(eventDetails) + strlen(other.eventDetails) + 1, other.eventDetails);

        // Return a new Event with combined details
        return Event(combinedDetails, eventDate, eventTime, maxTickets + other.maxTickets);
    }

    char operator[](int index) const {
        if (index < 0 || index >= strlen(eventDetails)) {
            throw out_of_range("Index out of bounds");
        }
        return eventDetails[index];
    }

    //getters 

    const char* getEventDetails() const{
        return this->eventDetails;
    }

    const char* getEventDate() const {
        return this->eventDate;
    }

    int getMaxTickets() const {
        return this->maxTickets;
    }

    const char* getEventTime() const{
        return this->eventTime;
    }

    //setters

    void setEventDetails(const char* details) {
        delete[] this->eventDetails;
        this->eventDetails = new char[strlen(details) + 1];
        strcpy_s(this->eventDetails, strlen(details) +1, details);
    }

    void setEventDate(const char* date) {
        delete[] this->eventDate;
        this->eventDate = new char[strlen(date) + 1];
        strcpy_s(this->eventDate, strlen(date) + 1, date);
    }
    
    void setEventTime(const char* time) {
        delete[] this->eventTime;
        this->eventTime = new char[strlen(time) + 1];
        strcpy_s(this->eventTime, strlen(time) + 1, time);
    }

    void setMaxTickets(int tickets) {
        this->maxTickets = tickets;
    }

    void displayEventInfo() const {
        cout << "Event Details: " << this->eventDetails << "\nDate: " << this->eventDate << "\nTime: " << this->eventTime << "\nMax Tickets: " << this->maxTickets << endl;
    }


};