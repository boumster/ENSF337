#include "Flight.h"
#include <iostream>
#include <iomanip> 
using namespace std;

Flight::Flight(string flightName, int rows, int cols) : flightName(flightName) {
    for (int i = 0; i < rows; ++i) {
        vector<Seat*> row;
        for (int j = 0; j < cols; ++j) {
            row.push_back(new Seat(i, j));
        }
        seats.push_back(row);
    }
}

Flight::Flight(const Flight& other) : flightName(other.flightName), seats(other.seats), passengers(other.passengers) {}

Flight& Flight::operator=(const Flight& other) {
    if (this != &other) {
        flightName = other.flightName;
        seats = other.seats;
        passengers = other.passengers;
    }
    return *this;
}

Flight::~Flight() {
    for (auto& row : seats) {
        for (auto& seat : row) {
            delete seat;
        }
    }
}

void Flight::addPassenger(string id, string firstName, string lastName, string phoneNumber, int row, int col) {
    Passenger* passenger = new Passenger(firstName, lastName, phoneNumber, id);
    seats[row][col]->setPassenger(passenger);
    passenger->setSeat(seats[row][col]);
    passengers.push_back(passenger);
}

void Flight::removePassenger(string id) {
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i]->getIdNumber() == id) {
            seats[passengers[i]->getSeat()->getRow()][passengers[i]->getSeat()->getCol()]->setPassenger(nullptr);
            delete passengers[i]; // Call the destructor of the Passenger object
            passengers.erase(passengers.begin() + i);
            break;
        }
    }
}

void Flight::showFlightSeatMap() const {
    cout << setw(5) << "";
    for(int i = 0; i < seats[0].size(); i++) {
        char ch = 'A';
        ch += i;
        cout << " " << ch << "  ";
    }
    cout << endl;

    for (int i = 0; i < seats.size(); i ++) {
        cout << setw(2) << i + 1 << "  |";
        for (int j = 0; j < seats[i].size(); j++) {
            if (seats[i][j]->getPassenger() == nullptr) {
                cout << "   |";
            } else {
                cout << " X |";
            }
        }
        cout << endl;
}
}

void Flight::showPassengersInfo() const {
    cout << left << setw(12) << "First Name" << setw(12) << "Last Name" << setw(12) << "Phone" << setw(6) << "Row" << setw(6) << "Seat" << setw(10) << "ID" << endl;
    for (int i = 0; i < passengers.size(); i++) {
        cout << "------------------------------------------------------" << endl; // Added to make the output more readable
        Seat  *seat = passengers[i]->getSeat();
        char col = 'A' + seat->getCol(); // Call getCol as a function
        int row = seat->getRow() + 1; // Call getRow as a function
        cout << left << setw(12) << passengers[i]->getFirstName() 
             << setw(12) << passengers[i]->getLastName() 
             << setw(12) << passengers[i]->getPhoneNumber() 
             << setw(6) << row 
             << setw(6) << col 
             << setw(10) << passengers[i]->getIdNumber() << endl; // Moved ID to the end
    }
}
bool Flight::isSeatAvailable(int row, int col) const {
    if(seats[row][col]->getPassenger() == nullptr) {
        return true;
    }
    return false;
}

string Flight::getFlightName() const { return flightName; }
vector<vector<Seat*>> Flight::getSeats() const { return seats; }