//*************************************
//
// DVD class implementation file
//
// Corey Farnsworth
// 07/07/18
// CS2401 Summer '18
//
//*************************************

#include "dvd.h"
using namespace std;

void Dvd::input(std::istream& ins){
	char junk;
  ins.get(junk);

  if(&ins == &cin){
    cout << "Enter movie title: ";
  }
	getline(cin, title);
  if(ins.eof())cout << "eof\n";

  if(&ins == &cin){
    cout << "Enter movie year: ";
  }
  ins >> year;

  if(&ins == &cin){
    cout << "Enter movie run time: ";
  }
  ins >> run_time;

  ins.get(junk);
   if(&ins == &cin){
    cout << "Enter movie type: ";
  }
  getline(cin, movie_type);
  if(ins.eof())cout << "eof\n";

  do{
    cout << "Enter a valid movie rating: ";
    getline(cin, rating);
  }while(rating != "G" && rating != "PG-13" && rating != "R" && rating != "X");

  cout << endl;
}

void Dvd::output(std::ostream& outs)const{
  if(&outs == &cout){
    outs << "title: " << title << endl;
    outs << "year: " << year << endl;
    outs << "run time (in minutes): " << run_time << endl;
    outs << "movie type: " << movie_type << endl;
    outs << "rating: " << rating << endl << endl;
  }
  else{
    outs << title << endl;
    outs << year << endl;
    outs << run_time << endl;
    outs << movie_type << endl;
    outs << rating << endl;
  }
}

string Dvd::get_title()const{
  return title;
}

int Dvd::get_year()const{
  return year;
}

int Dvd::get_run_time()const{
  return run_time;
}

string Dvd::get_movie_type()const{
  return movie_type;
}

string Dvd::get_rating()const{
  return rating;
}

void Dvd::set_title(string t){
  title = t;
}

void Dvd::set_year(int y){
  year = y;
}

void Dvd::set_run_time(int rt){
  run_time = rt;
}

void Dvd::set_movie_type(string mt){
  movie_type = mt;
}

void Dvd::set_rating(string r){
  rating = r;
}

std::ostream& operator <<(std::ostream& outs, const Dvd& dvd1){
	dvd1.output(outs);
	return outs;
}

std::istream& operator >> (std::istream& ins, Dvd& dvd1){
	dvd1.input(ins);
	return ins;
}
