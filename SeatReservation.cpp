#include "SeatReservation.h"
#include <fstream>
#include <string>
#include <map>
using namespace std;

bool reserve(char seats[7][4], int row, int col){
	if(seats[row-1][col-1] == 'x') {
    cout << "That seat is already taken"<<endl;
    return false;
  }
  seats[row-1][col-1] = 'x';
  return true;
}
//reserve function
void display(char seats[7][4]){
	cout <<"*****************"<<endl;
	cout <<"    Seat Chart   "<<endl;
  cout <<"*****************"<<endl;
	cout <<"  ABCD"<<endl;
	cout <<"1 "<<seats[0][0]<<seats[0][1]<<seats[0][2]<<seats[0][3]<<endl;
	cout <<"2 "<<seats[1][0]<<seats[1][1]<<seats[1][2]<<seats[1][3]<<endl;
	cout <<"3 "<<seats[2][0]<<seats[2][1]<<seats[2][2]<<seats[2][3]<<endl;
	cout <<"4 "<<seats[3][0]<<seats[3][1]<<seats[3][2]<<seats[3][3]<<endl;
	cout <<"5 "<<seats[4][0]<<seats[4][1]<<seats[4][2]<<seats[4][3]<<endl;
	cout <<"6 "<<seats[5][0]<<seats[5][1]<<seats[5][2]<<seats[5][3]<<endl;
	cout <<"7 "<<seats[6][0]<<seats[6][1]<<seats[6][2]<<seats[6][3]<<endl;
}
//display function, outputs all positions of array
bool cancel(char seats[7][4], int row, int col){
  if(seats[row-1][col-1] == ' ') {
		cout << "That seat is already empty"<<endl;
    return false;
	}
	seats[row-1][col-1] = ' ';
  return true;
}
//cancel function

void ResetSeating(char seats[7][4]){
  for(char i = 0; i < 7; i++){
    for(char j = 0; j < 4; j++){
      seats[i][j] = ' ';
    }
  }
}
//function to reset all values of the array
void ReservedSeats(char seats[7][4]){
  // [ROWS][COLUMNS]
  // Rows: 0-6
  // Columns: A-D (0-3)
  seats[0][3] = 'x';
  seats[1][1] = 'x';
  seats[3][2] = 'x';
  seats[6][0] = 'x';
}

// Takes in string such as "1D" and converts it to a position
// Positions range from 1-7 rows and 1-4 columns
void getPosition(string pos, int& row, int& col){
  map<char, int> translator;
  translator['a'] = 1;
  translator['b'] = 2;
  translator['c'] = 3;
  translator['d'] = 4;
 // translate a to 1, b to 2, etc
  row = stoi(pos.substr(0,1));
  col = translator[pos[1]];
}

bool FlightReservationMenu(char seats[7][4]){
	cout << "Seat Reservation and Cancellation Menu" << endl;
	cout << "Display Available Seats: D" << endl;
	cout << "Reserve Seat           : R" << endl;
	cout << "Cancel Seat            : C" << endl;
	cout << "Quit                   : Q" << endl;
	//base level menu
  char input = valid<char>("Enter your choice");
  int row = 1, col = 1;
  string position = "";
	
  switch(input){
		case 'd':
		case 'D':
			display(seats);
			break;
			//if switch is set to d, run display function
		case 'r':
		case 'R':
      position = valid<string>("Enter a position (e.g. 1a)");
      getPosition(position, row, col);
			reserve(seats, row, col);
			break;
			//if switch is set to r, run reserve function
		case 'c':
		case 'C':
			position = valid<string>("Enter a position (e.g. 1a)");
      getPosition(position, row, col);
			cancel(seats, row, col);
			break;
			//if switch is set to c, run cancel function
		case 'q':
		case 'Q':
			return false;
			break;
			//if switch is set to q, break out of switch
		default:
			cout << "That is not an option."<<endl;
	}
  return true;
}