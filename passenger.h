#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "Seat.h" // Include Seat header file
using namespace std;

class Passenger {
public:
    Passenger(string firstName, string lastName, string phoneNumber, string idNumber);
    Passenger(const Passenger& other); // Copy constructor
    Passenger& operator=(const Passenger& other); // Assignment operator
    ~Passenger(); // Destructor

    string getFirstName() const;
    string getLastName() const;
    string getPhoneNumber() const;
    string getIdNumber() const;
    Seat* getSeat() const;

    void setFirstName(string fName);
    void setLastName(string lName);
    void setPhoneNumber(string phone);
    void setIdNumber(string id);
    void setSeat(Seat* seat);

private:
    string firstName;
    string lastName;
    string phoneNumber;
    string idNumber;
    Seat* seatPtr;
};

#endif // PASSENGER_H