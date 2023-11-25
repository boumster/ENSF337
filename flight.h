#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>
#include "Passenger.h"
#include "Seat.h"
using namespace std;

class Flight {
public:
    Flight(string flightName, int rows, int cols);
    Flight(const Flight& other); // Copy constructor
    Flight& operator=(const Flight& other); // Assignment operator
    ~Flight(); // Destructor

    void addPassenger(string id, string firstName, string lastName, string phoneNumber, int row, int col);
    void removePassenger(string id);
    void showFlightSeatMap() const;
    void showPassengersInfo() const;

    string getFlightName() const;
    vector<vector<Seat*>> getSeats() const;
    bool isSeatAvailable(int row, int col) const;

private:
    string flightName;
    vector<vector<Seat*>> seats;
    vector<Passenger*> passengers;
};

#endif // FLIGHT_H