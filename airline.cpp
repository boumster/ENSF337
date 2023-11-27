// Airline.cpp

#include "Airline.h"

Airline::Airline(const string& airlineName) : name(airlineName) {}

Airline::Airline(const Airline& other) : name(other.name), flights(other.flights) {}

Airline& Airline::operator=(const Airline& other) {
    if (this != &other) {
        name = other.name;
        flights = other.flights;
    }
    return *this;
}

void Airline::addFlight(Flight* flight) {
    flights.push_back(flight);
}

Flight* Airline::getFlight(const string& flightName) {
    for (Flight* flight : flights) {
        if (flight->getFlightName() == flightName) {
            return flight;
        }
    }
    return nullptr;
}

string Airline::getName() const {
    return name;
}

Airline::~Airline() {
    for (Flight* flight : flights) {
        delete flight;
    }
}