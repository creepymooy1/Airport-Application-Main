#pragma once
#include <array>
#include "./Utils.h"
using namespace std;

void ResetSeating(char seats[7][4]);
void ReservedSeats(char seats[7][4]);
void getPosition(string pos, int& row, int& col);
bool FlightReservationMenu(char seats[7][4]);
bool reserve(char seats[7][4], int row, int col);
void display(char seats[7][4]);
bool cancel(char seats[7][4], int row, int col);