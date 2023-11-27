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
    int getRow() const;
    int getCol() const;

    string getFlightName() const;
    vector<vector<Seat*>> getSeats() const;
    vector<Passenger*> getPassengers() const;
    bool isSeatAvailable(int row, int col) const;
    bool isIdAvailable(const string& id) const;

private:
    string flightName;
    vector<vector<Seat*>> seats;
    vector<Passenger*> passengers;
    int rowsM;
    int colsM;
};

#endif // FLIGHT_H