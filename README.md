# Airport-Application-Main

This is a text-based airport application that provides basic features such as flight status report, seat reservation, movie selection, and emergency decision-making for clients. This program can be used to book a seat on a flight, check the status of a flight, select a movie to watch, and help the crew make decisions in case of an emergency.

# Features
Flight Status Report:

This feature allows the user to check the status of flights. The user can select the option to view either arrival or departure times. The information is stored in separate text files for arrivals and departures. The data is displayed in a formatted table with the flight number, gate number, airport, scheduled time, expected time, and delay.

Seat Reservation:

This feature allows the user to book a seat on a flight. The system displays the seating arrangement, and the user can select a seat to reserve. The system then updates the seating arrangement and marks the selected seat as reserved. The system also prevents the user from selecting a seat that has already been reserved.

Movie Selector:

This feature allows the user to select a movie to watch during the flight. The system displays a list of available movies, and the user can choose to view the list or search for a movie by year. The movie data is stored in a text file with the movie name, release year, director, genre, and two main actors. The system sorts the movies by year of release and allows the user to search for a movie by year.

Emergency Decision-Making:

This feature provides the crew with decision trees to follow in case of an emergency. The program provides decision trees for communication failure, engine failure, and in-flight icing. The decision trees ask a series of questions to help the crew determine the appropriate actions to take in each situation.

# Modules
The following modules make up the text-based airport application:

Utils.h: This header file contains utility functions used by the other modules, such as input validation functions.

FlightStatus.h: This header file contains the function declarations for checking the arrival and departure times of flights.

FlightStatus.cpp: This module contains the implementations of the functions for checking the arrival and departure times of flights.

SeatReservation.h: This header file contains the function declarations for reserving seats on a flight.

SeatReservation.cpp: This module contains the implementations of the functions for reserving seats on a flight.

Movie.h: This header file contains the Movie struct declaration.

MovieFunctions.h: This header file contains the function declarations for searching and displaying movies.

MovieFunctions.cpp: This module contains the implementations of the functions for searching and displaying movies.

EmergencyDecisionsFunctions.h: This header file contains the function declarations for the decision trees used in case of an emergency.

EmergencyDecisionsFunctions.cpp: This module contains the implementations of the decision trees used in case of an emergency.

main.cpp: This module contains the main function that calls the other modules to run the text-based airport application.
