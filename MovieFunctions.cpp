#include <array>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "./Utils.h"
#include "MovieFunctions.h"
using namespace std;

void showMovies(array<Movie*, 6>& movieVec) {
  for(auto i : movieVec){
    cout 
      << i->name << " " 
      << i->year << " " 
      << i->director << " " 
      << i->genre << " " 
      << i->actor1 << " " 
      << i->actor2 << "\n\n";
  }
}

void parseFile(string fileName, array<Movie*, 6>& movieVec){
	ifstream file;
	file.open("MovieData.txt");
  
	if (!file.is_open()) {
		cout<< "File Error: Please exit the application\n";
	}
	else {
    string s;
    Movie temp;
    int index = 0;
		while (getline(file, s)){
      
      stringstream ss = stringstream(s);

      ss >> temp.name;
			ss >> temp.year;
			ss >> temp.director;
			ss >> temp.genre;
			ss >> temp.actor1;   
      ss >> temp.actor2;

      *movieVec[index++] = temp;
		}
	}
  
}

void searchMovies(array<Movie*, 6>& movieVec){
  int searchYear = valid<int>("Please enter the year of a movie: ");

  Movie searchM;
  searchM.year = searchYear;

	if(binary_search(movieVec.begin(), movieVec.end(), &searchM, 
    [](const Movie* i, const Movie* j){
      return *i < *j;
    })){

    auto it = find_if(movieVec.begin(), movieVec.end(), [=](const Movie* i){
      return i->year == searchM.year;
    });

    if(it != movieVec.end()){
      auto x = *it;
      cout 
        << "\n"
        << x->name << " " 
        << x->year << " " 
        << x->director << " " 
        << x->genre << " " 
        << x->actor1 << " " 
        << x->actor2 << "\n\n";
    }
	}

}

bool movieSelectorMenu(array<Movie*, 6>& movieVec) {

  cout << "================================" << endl;
	cout << "| Display Available Movies : D |" << endl;
	cout << "| Search a Movie by Year   : S |" << endl;
	cout << "| Quit                     : Q |" << endl;
	cout << "================================ \n \n";
	
  char choice = valid<char>("Enter your selection");
	
	switch (choice){
		case 'd':
		case 'D':
			showMovies(movieVec);
			break;
		case 's':
		case 'S':
			searchMovies(movieVec);
			break;
		case 'q':
		case 'Q':
			return false;
			break;
		default:
			cout << "Enter a valid choice" << endl;
	}

	return true;
}