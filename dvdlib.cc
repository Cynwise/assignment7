//*************************************
//
// DVDLIB class implementation file
//
// Corey Farnsworth
// 07/07/18
// CS2401 Summer '18
//
//*************************************

#include "dvdlib.h"

using namespace std;

void Dvdlib::insert(const Dvd& item){
	if(used < CAPACITY){
		data[used] = item;
		used++;
	}
	else{
		cout<<"Error. List capacity has been reached. Remove a DVD.\n";
	}
}

void Dvdlib::see_all()const{
  if(used == 0)
    cout << "Empty list.\n";
  else
    for(size_t i = 0; i < used; ++i)
    cout << data[i] << endl;
}

void Dvdlib::search(const string& target)const{
	size_t i = 0;
	while(i < used && data[i].get_title() != target) ++i;
		if(i == used){
			cout << "not found!!\n";

		}

		else{
			cout << "Movie Found!\n";
			cout << data[i];
		}
}
void Dvdlib::remove(const string& title){
	size_t i = 0;
	while(i < used && data[i].get_title() != title) ++i;
		if(i == used)
			cout << "not found!\n";
		else{
			cout << "Movie deleted\n";
			//copy end of list item to found location and decrease array size
			data[i] = data[used];
			used --;
		}
}

void Dvdlib::search_by_rating(const string& target_rating){
	size_t i = 0;
	do{
		while(i < used && data[i].get_rating() != target_rating) ++i;
			if(i == used){
				cout << "All movies of given rating.";
			}
			else{
				if(data[i].get_rating() == target_rating){
					cout << data[i] << endl;
				}
			}
			++i;
	}while(i != used);
	cout << "All movies of given rating.\n";
}


void Dvdlib::sort_by_year(){
	int small_year;
	int j;

	for(int i = 0; i < used; ++i){
		small_year = i;
		for(j = i; j < used; ++j){
			if(data[j].get_year() < data[small_year].get_year()){
				small_year = j;
			}
		}
		if(small_year != i){
			Dvd tmp;
			tmp = data[i];
			data[i] = data[small_year];
			data[small_year] = tmp;
		}
	}
}

void Dvdlib::sort_by_title(){
	int small_title;
	int j;

	for(int i = 0; i < used; ++i){
		small_title = i;
		for(j = i; j < used; ++j){
			if(data[j].get_title() < data[small_title].get_title()){
				small_title = j;
			}
		}
		if(small_title != i){
			Dvd tmp;
			tmp = data[i];
			data[i] = data[small_title];
			data[small_title] = tmp;
		}
	}
}

void Dvdlib::save_to_file(ofstream& outs){
	for(int i = 0; i <= used - 1; ++i ){
		outs << data[i];
		//outs << endl;
	}
}

void Dvdlib::load_from_file(ifstream& ins){
	Dvd tmp;
	string tmp_title;
	int tmp_year;
	int tmp_run_time;
	string tmp_movie_type;
	string tmp_rating;

	while(!ins.eof()){

		if(ins.peek() == '\n'){
			ins.ignore();
		}

	getline(ins, tmp_title);
	tmp.Dvd::set_title(tmp_title);

	if(ins.peek() == '\n'){
		ins.ignore();
	}

	ins >> tmp_year;
	tmp.Dvd::set_year(tmp_year);
	if(ins.peek() == '\n'){
		ins.ignore();
	}

	ins >> tmp_run_time;
	tmp.Dvd::set_run_time(tmp_run_time);

	if(ins.peek() == '\n'){
		ins.ignore();
	}

	getline(ins, tmp_movie_type);
	tmp.Dvd::set_movie_type(tmp_movie_type);

	if(ins.peek() == '\n'){
		ins.ignore();
	}

	ins >> tmp_rating;
	tmp.Dvd::set_rating(tmp_rating);

	if(ins.peek() == '\n'){
		ins.ignore();
	}

	Dvdlib::insert(tmp);


	}
}
