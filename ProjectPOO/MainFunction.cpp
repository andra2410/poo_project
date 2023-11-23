#include<iostream>
#include "Event.cpp"

using namespace std;

int main() {
	
	Event event1("event 1", "2023-11-22", "18:00", 100);
	cout << "event details: " << event1.getEventDetails() << endl;
	cout << "event date: " << event1.getEventDate() << endl;
	cout << "event time: " << event1.getEventTime() << endl;
	cout << "maxTickets for the " << event1.getEventDetails() << " are " << event1.getMaxTickets();






}
