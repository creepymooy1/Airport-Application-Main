#include <iostream>
#include <array>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "EmergencyDecisionsFunctions.h"
#include "FlightStatus.h"
#include "SeatReservation.h"
#include "MovieFunctions.h"
#include "Utils.h"

using namespace std;

bool FlightStatusReportMenu(){
	cout << "Flight Status Report Menu" <<endl;
	cout << "Enter A for Arrival Times, D for departure times, or Q to quit."<<endl;
	char input = valid<char>("Enter selection");
	switch(input){
		case 'a':
		case 'A':
			ArrivalTimes();
			break;
		case 'd':
		case 'D':
			DepartureTimes();
			break;
		case 'q':
		case 'Q':
			return false;
			break;
		default:
			cout << "That is not an option."<<endl;
	}
  return true;
}

bool emergencyDecisionsMenu(){
	cout << "Aircraft Emergency Decision Program \n";
	cout << "======================================= \n";
	cout << "Enter 'C' for Communications Failure, \n'E' for Engine Failure, \n'I' for In flight Icing, or \n'Q' to Quit. \n";

  char option = valid<char>("Enter selection");
  switch(option){
    case 'c':
    case 'C':
      CommunicationsTree();
			break;
    case 'E':
    case 'e':
      EngineTree();
      break;
		case 'I':
    case 'i':
			IcingTree();
      break;
		case 'Q':
    case 'q':
      return false;
      break;
    default:
      cout << "That is not one of the options\n";
  }
  return true;
}

bool reservationMenu(){
  char seats[7][4];
  
  ResetSeating(seats);
	//reset the array
  ReservedSeats(seats);
	//set 1d, 2b, 4c, and 7a to reserved
  while(FlightReservationMenu(seats));
  return false;
}

bool movieMenu(){

 array<Movie*, 6> movieVec;

  for(int i = 0; i < movieVec.size(); i++){
    movieVec[i] = new Movie();
  }

  parseFile("MovieData.txt", movieVec);
  
  sort(movieVec.begin(), movieVec.end(), [](Movie* i, Movie* j){
    return i->year < j->year;
  });
  
	bool choice = movieSelectorMenu(movieVec);
	while (choice) {
		choice = movieSelectorMenu(movieVec);
	}
  for(int i = 0; i < movieVec.size(); i++){
    delete movieVec[i];
    movieVec[i] = nullptr;
  }
  return false;
}

void mainMenu(){
	cout << "Airport Program Main Menu \n";
	char mainOption = valid<char>("Choose: \nE for Emergency Decision, \nS for Status Report Menu, \nR for Seat Reservation System, and \nM for Movie Selector. \n");
	switch(mainOption){
		case 'e':
		case 'E':
		  while(emergencyDecisionsMenu());
      break;
		case 's':
		case 'S':
      while(FlightStatusReportMenu()); 
      break;
		case 'r':
		case 'R':
		  while(reservationMenu());
      break;
		case 'm':
		case 'M':
		  while(movieMenu());
			break;
	}
}

int main() {
  mainMenu();
  return 0;
}