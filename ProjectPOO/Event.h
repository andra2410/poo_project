#pragma once
#include <iostream>
using namespace std;

class Event {
private:
    char* eventDetails;
    char* eventDate;
    char* eventTime;
    int maxTickets;

public:
    Event();
    Event(const char* eventDetails, const char* eventDate, const char* eventTime, int maxTickets);

    Event(const Event& other);
    ~Event();

    Event& operator=(const Event& other);

    friend std::ostream& operator<<(std::ostream& os, const Event& event);

    Event operator+(const Event& other) const;

    char operator[](int index) const;

    const char* getEventDetails() const;
    const char* getEventDate() const;
    const char* getEventTime() const;
    int getMaxTickets() const;

    void setEventDetails(const char* details);
    void setEventDate(const char* date);
    void setEventTime(const char* time);
    void setMaxTickets(int tickets);

    void displayEventInfo() const;
    void processEvent();
};