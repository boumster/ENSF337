#include "Seat.h"
#include "Passenger.h" // Include Passenger header file


Seat::Seat(int row, int col) : row(row), col(col), passenger(nullptr) {}

Seat::Seat(const Seat& other) : row(other.row), col(other.col), passenger(other.passenger) {}

Seat& Seat::operator=(const Seat& other) {
    if (this != &other) {
        row = other.row;
        col = other.col;
        passenger = other.passenger;
    }
    return *this;
}

Seat::~Seat() {
}

int Seat::getRow() const { return row; }
int Seat::getCol() const { return col; }
Passenger* Seat::getPassenger() const { return passenger; }

void Seat::setRow(int r) { row = r; }
void Seat::setCol(int c) { col = c; }
void Seat::setPassenger(Passenger* p) { passenger = p; }