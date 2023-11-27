// main.h

#ifndef MAIN_H
#define MAIN_H

#include "Flight.h"
#include <string>
using namespace std;

void add_passenger(Flight* flight);
void display_passengers_info(Flight* flight);
void display_seat_map(Flight* flight);
void remove_passenger(Flight* flight);
void save_data(Flight* flight);
void load_data(const string& filename, Airline* airline);
string trim(const string& str);
void menu();
void display_header();

#endif // MAIN_H