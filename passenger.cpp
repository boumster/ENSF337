#include "Passenger.h"

Passenger::Passenger(string firstName, string lastName, string phoneNumber, string idNumber)
    : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), idNumber(idNumber), seatPtr(nullptr) {}

Passenger::Passenger(const Passenger& other)
    : firstName(other.firstName), lastName(other.lastName), phoneNumber(other.phoneNumber), idNumber(other.idNumber), seatPtr(other.seatPtr) {}

Passenger& Passenger::operator=(const Passenger& other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        phoneNumber = other.phoneNumber;
        idNumber = other.idNumber;
        seatPtr = other.seatPtr;
    }
    return *this;
}

Passenger::~Passenger() {
}

string Passenger::getFirstName() const { return firstName; }
string Passenger::getLastName() const { return lastName; }
string Passenger::getPhoneNumber() const { return phoneNumber; }
string Passenger::getIdNumber() const { return idNumber; }
Seat* Passenger::getSeat() const { return seatPtr; }

void Passenger::setFirstName(string fName) { firstName = fName; }
void Passenger::setLastName(string lName) { lastName = lName; }
void Passenger::setPhoneNumber(string phone) { phoneNumber = phone; }
void Passenger::setIdNumber(string id) { idNumber = id; }
void Passenger::setSeat(Seat* seat) { seatPtr = seat; }