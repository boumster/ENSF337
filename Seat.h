#ifndef SEAT_H
#define SEAT_H

class Passenger;

class Seat {
public:
    Seat(int row, int col);
    Seat(const Seat& other); // Copy constructor
    Seat& operator=(const Seat& other); // Assignment operator
    ~Seat(); // Destructor

    int getRow() const;
    int getCol() const;
    Passenger* getPassenger() const;

    void setRow(int r);
    void setCol(int c);
    void setPassenger(Passenger* p);

private:
    int row;
    int col;
    Passenger* passenger; // Pointer to Passenger
};

#endif // SEAT_H