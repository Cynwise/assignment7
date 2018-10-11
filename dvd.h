//************************************
//
//  Project 1
//
//  This class is capable of storing
//  one DVD.
//
//  Corey Farnsworth
//  07/07/18
//  CS2401 Summer '18
//
//************************************
#ifndef DVD
#define DVD

//#include "dvdlib.h"


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>

using namespace std;

//class Dvdlib;

class Dvd{
  public:
    //default contructor
    Dvd(){
      title = "none";
      year = 0000;
      run_time = 0;
      movie_type = "none";
      rating = "none";
    };

    //accessor functions
    string get_title()const;
    int get_year()const;
    int get_run_time()const;
    string get_movie_type()const;
    string get_rating()const;

    //mutator functions
    void set_title(string t);
    void set_year(int y);
    void set_run_time(int rt);
    void set_movie_type(string mt);
    void set_rating(string r);


    //is called by insertion operator
    void input(std::istream& ins);

    //is called by extraction operator
    void output(std::ostream& outs) const;


  private:
    string title;
    int year;
    int run_time;
    string movie_type;
    string rating;
};

//extraction and insertion operators being called by input and output funcs
std::istream& operator >>(std::istream& ins, Dvd& dvd1);
std::ostream& operator <<(std::ostream& outs, const Dvd& dvd1);

#endif
