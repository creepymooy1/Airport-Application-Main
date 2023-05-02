#pragma once

#include <string>
#include "./Utils.h"
using namespace std;
struct Movie {
  string name, director, genre, actor1, actor2;
  int year;

  friend bool operator<(const Movie& a, const Movie& b){
    return a.year < b.year;
  }

  friend bool operator==(const Movie& a, const Movie& b){
    return a.year == b.year;
  }

  Movie& operator=(const Movie& other){
    year = other.year;
    name = other.name;
    director = other.director;
    genre = other.genre;
    actor1 = other.actor1;
    actor2 = other.actor2;
    return *this;
  }

};

void showMovies(array<Movie*, 6>& movieVec);
void parseFile(string fileName, array<Movie*, 6>& movieVec);
void searchMovies(array<Movie*, 6>& movieVec);
bool movieSelectorMenu(array<Movie*, 6>& movieVec);