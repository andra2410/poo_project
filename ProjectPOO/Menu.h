#pragma once
#include <iostream>
#include "Event.h"
#include "EventLocation.h"
#include "Ticket.h"

class Menu {
public:
    static void displayMainMenu();
    static void processOption(int option, Event& event, EventLocation& eventLocation, Ticket& ticket);
};