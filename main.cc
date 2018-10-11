//*************************************
//
// Project 1 Main File
//
// Corey Farnsworth
// 07/07/18
// CS2401 Summer '18
//
//*************************************


#include "dvd.h"
#include "dvdlib.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main(){

  Dvd dvd1;
  Dvdlib lib1;
  string target_rating;
  string target;
  string tmp_title;
  int menu_choice;
  string title;

  ifstream ifs("movies.dat");
  if(!ifs.fail()){
    lib1.load_from_file(ifs);
  }
  ifs.close(); 

  ofstream outs("movies.dat");

do{
    cout << "Welcome to the DVD library!\n";
    cout << "1.) Insert a movie\n";
    cout << "2.) Remove a movie from the list\n";
    cout << "3.) Display all movies in the list\n";
    cout << "4.) Display all movies of a chosen rating\n";
    cout << "5.) Search for a movie by title\n";
    cout << "6.) Display movies alphabetically by title\n";
    cout << "7.) Display movies by the year made\n";
    cout << "8.) Quit Program\n\n";

    // clear any leftover characters in cache
    title.clear();
    cout << "Please make a menu selection: ";
    cin >> menu_choice;


    switch(menu_choice){
      case 1:
        cout << "Plese enter the movie: \n";
        dvd1.Dvd::input(cin);
        lib1.Dvdlib::insert(dvd1);
        break;

      case 2:
        cout << "Please enter the exact title of the movie you want to remove: \n";
        //check for newline characters
        if(cin.peek() == '\n'){
          cin.ignore();
        }
        getline(cin, title);
        lib1.Dvdlib::remove(title);
        break;

      case 3:
        cout << "Displaying all movies in the list: \n\n";
        lib1.Dvdlib::see_all();
        break;

      case 4:
      do{
        cout << "Please enter a rating to search by: ";
        cin >> target_rating;
          lib1.Dvdlib::search_by_rating(target_rating);
        }while(target_rating != "G" && target_rating != "PG-13" && target_rating != "R" && target_rating != "X");
        break;

      case 5:
        cout << "please enter the title of the movie: ";
        //check for newline characters
        if(cin.peek() == '\n'){
          cin.ignore();
        }
        getline(cin, target);
        cout << "Something is here:" << target << "between here" << endl << endl;
        lib1.Dvdlib::search(target);
        break;

      case 6:
        cout << "Sorting movies by title: \n\n";
        lib1.Dvdlib::sort_by_title();
        lib1.Dvdlib::see_all();
        break;

      case 7:
        cout << "Sorting movies by year released: \n\n";
        lib1.Dvdlib::sort_by_year();
        lib1.Dvdlib::see_all();
        break;

      case 8:
        cout << "Goodbye\n";
        lib1.save_to_file(outs);
        outs.close();
        return(0);

      default:
        cout << "ERROR. Please enter proper selection\n\n";
        break;
      }
    }while(menu_choice != 8);
}
