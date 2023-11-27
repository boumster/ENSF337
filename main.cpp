#include "Airline.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

void add_passenger(Flight* flight);
void display_passengers_info(Flight* flight);
void display_seat_map(Flight* flight);
void remove_passenger(Flight* flight);
void save_data(Flight* flight);
Flight* load_data(const string& filename);
string trim(const string& str);
void menu();
void display_header();

int main() {
    // Create a Flight
    Airline* airline = new Airline("WestJet");
    Flight* flight = load_data("entry_data.txt");
    airline->addFlight(flight);
    display_header();

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                display_seat_map(flight);
                break;
            case 2:
                display_passengers_info(flight);
                break;
            case 3:
                add_passenger(flight);
                break;
            case 4:
                remove_passenger(flight);
                break;
            case 5:
                save_data(flight);
                break;
            case 6:
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}

void add_passenger(Flight* flight) {
    int row, col;
    char colChar;
    string id;
    string first_name;
    string last_name;
    string phone_number;
    do {
        cout << "Please enter the passenger id: ";
        cin >> id;
        if(flight->isIdAvailable(id) == false) {
            cout << "ID is not available. Please choose another ID." << endl;
        }
    } while (flight->isIdAvailable(id) == false);
    cout << "Pleanse enter the passenger first name: ";
    cin >> ws; // This will consume any leading whitespace
    getline(cin, first_name);
    cout << "Please enter the passenger last name: ";
    cin >> ws; // This will consume any leading whitespace
    getline(cin, last_name);
    cout << "Please enter the passenger phone number: ";
    cin >> ws; // This will consume any leading whitespace
    getline(cin, phone_number);
    do {
        cout << "\nEnter the passenger's desired row: ";
        cin >> row;
        cout<< "Enter the passenger's desired seat: ";
        cin >> colChar;
        col = colChar - 'A';
        row -= 1;
        if (row < 0 || row >= flight->getRow() || col < 0 || col >= flight->getCol()) {
            cout << "Invalid seat. Please choose another seat." << endl;
        } else if (flight->isSeatAvailable(row, col) == false) {
            cout << "Seat is not available. Please choose another seat." << endl;
        }
    } while (row < 0 || row >= flight->getRow() || col < 0 || col >= flight->getCol() || flight->isSeatAvailable(row, col) == false);
    flight->addPassenger(id, first_name, last_name, phone_number, row, col);
}

void display_passengers_info(Flight* flight)
{
    cout << endl;
    flight->showPassengersInfo();
    cout << "\n<<< Press Return to Continue >>> \n";
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.get(); // Wait for user input
}

void display_seat_map(Flight* flight)
{
    cout << endl;
    flight->showFlightSeatMap();
    cout << "\n<<< Press Return to Continue >>> \n";
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.get(); // Wait for user input
}

void remove_passenger(Flight* flight) {
    string id;
    cout << "Please enter the ID of the passenger to remove: ";
    cin >> id;
    flight->removePassenger(id);
}

void save_data(Flight* flight) {

    char choice;
    do {
        cout << "Do you want to save the data in the \"flight_info.txt\"? Please answer <Y or N>: ";
        cin >> choice;
        if (choice == 'N') {
            return;
        }
    } while (choice != 'Y');

    ofstream file("flight_info.txt");

    if (file.is_open()) {
        // Write the flight name
        file << "Flight name: " << flight->getFlightName() << "\n";

        // Write the passengers' information
        file << left << setw(20) << "First Name" << setw(20) << "Last Name" << setw(15) << "Phone" << setw(6) << "Row" << setw(6) << "Seat" << setw(10) << "ID" << endl;
        vector<Passenger*> passengers = flight->getPassengers();
        for (int i = 0; i < passengers.size(); i++) {
            Passenger* passenger = passengers[i];
            if (passenger != nullptr) {
                Seat* seat = passenger->getSeat();
                char col = 'A' + seat->getCol();
                int row = seat->getRow() + 1;
                file << "-------------------------------------------------------------------------------" << endl;
                file << left << setw(20) << passenger->getFirstName() 
                    << setw(20) << passenger->getLastName() 
                    << setw(15) << passenger->getPhoneNumber() 
                    << setw(6) << row 
                    << setw(6) << col
                    << setw(10) << passenger->getIdNumber() << "\n";
            }
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }

    cout << "\nAll data in the passenger list was saved into the flight_data.txt file.\n";
    cout << "\n<<< Press Return to Continue >>> \n";
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.get(); // Wait for user input
}

Flight* load_data(const string& filename) {
    ifstream file(filename);

    Flight* flight = nullptr;

    if (file.is_open()) {
        string line;

        // Read the flight information
        if (getline(file, line)) {
            stringstream ss(line);
            string flightName;
            int rows, cols;
            ss >> flightName >> rows >> cols;

            // Create a new flight
            flight = new Flight(flightName, rows, cols);
        }

        // Read the passengers' information
        while (getline(file, line)) {
            string firstName = line.substr(0, 20);
            string lastName = line.substr(20, 20);
            string phoneNumber = line.substr(40, 20);
            string seat = line.substr(60, 4);
            string idNumber = line.substr(64, 5);

            // Trim the strings
            firstName = trim(firstName);
            lastName = trim(lastName);
            phoneNumber = trim(phoneNumber);
            seat = trim(seat);
            idNumber = trim(idNumber);

            // Convert seat to row and column
            int i = 0;
            int rowNum = 0;
            while (seat[i] >= '0' && seat[i] <= '9') {
                rowNum = rowNum * 10 + (seat[i] - '0');
                i++;
            }
            char seatCol = seat[i];

            // Add the passenger to the flight
            flight->addPassenger(idNumber, firstName, lastName, phoneNumber, rowNum - 1, seatCol - 'A');
        }

        file.close();
    } else {
        cout << "Unable to open file";
    }

    return flight;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void menu(){
    cout << endl << "Please select one of the following options:" << endl << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passengers Information" << endl;
    cout << "3. Add a new Passenger" << endl;
    cout << "4. Remove a Passenger" << endl;
    cout << "5. Save Data" << endl;
    cout << "6. Quit" << endl << endl;
    cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
}

void display_header(){
    cout << "VersionL 1.0" << endl;
    cout << "Term Project - Flight Management Program " << endl;
    cout << "Produced by: Phoenix Bouma" << endl;
    cout << "\n<<< Press Return to Continue >>> \n";
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.get(); // Wait for user input
}