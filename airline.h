// Airline.h

#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <vector>
#include "Flight.h"
using namespace std;

class Airline {
private:
    string name;
    vector<Flight*> flights;

public:
    Airline(const string& airlineName);
    Airline(const Airline& other); // Copy constructor
    Airline& operator=(const Airline& other); // Assignment operator
    ~Airline(); // Destructor

    void addFlight(Flight* flight);
    Flight* getFlight(const string& flightName);
    string getName() const;

    // Other member functions and data members can be added here
};
#endif // AIRLINE_H
