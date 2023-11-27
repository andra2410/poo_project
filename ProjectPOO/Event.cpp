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

};