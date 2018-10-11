//************************************
//
//  Project 1
//
//  This class is capable of storing
//  200 DVDs.
//
//  Corey Farnsworth
//  07/07/18
//  CS2401 Summer '18
//
//************************************

#ifndef DVDLIB
#define DVDLIB

#include "dvd.h"

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//class Dvd;
class Dvdlib{
  public:
    static const size_t CAPACITY = 200;

    //walks through array
    void see_all()const; //ostream &outs

    //inserts DVD to the end of array
    void insert(const Dvd& item);

    //searches and removes passed dvd based on title
    void remove(const string& title);

    //searches for exact title and returns it
    void search(const string& target)const;

    //searches array for all movies with certain rating
    void search_by_rating(const string& target_rating);

    //selection sorts movies by year
    void sort_by_year();

    //selection sorts movies by title
    void sort_by_title();

    //outputs array to file at end of program
    void save_to_file(ofstream& outs);

    //loads DVDs from file into array at start of program
    void load_from_file(ifstream& ins);

  private:
    Dvd data[CAPACITY];
    size_t used = 0;
};

#endif
