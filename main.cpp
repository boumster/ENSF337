#include "flight.h"
#include <iostream>
using namespace std;

int main() {
    // Create a Flight
    Flight flight("Flight 101", 10, 10);

    // Print the flight name
    cout << "Flight name: " << flight.getFlightName() << endl;
    flight.addPassenger("10002", "John", "Doe", "1234567890", 3, 8);
    flight.addPassenger("10001", "Jane", "Doe", "0987654321", 5, 9);
    flight.showPassengersInfo();
    // Show the flight seat map
    flight.showFlightSeatMap();

    return 0;
}