#pragma once
#include <list>
#include <string>
#include <ctime>
#include <time.h>
#include <math.h>
#include <limits>
#include <vector>
#include <queue>
#include <cfloat>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::vector;
using std::list;

class Model;
class Books;
class Users;

class IObserver
{
public:
    virtual void handleEvent( Model&)=0 ;
    
};

// --------------------------VIEW---------------------------------
class View: public IObserver {
public:
	
	void PrintHelp(){
		cout<<"type 'quit' to exit program"<<endl;
		cout<<"type 'books' to see available books"<<endl;
		cout<<"tpe 'users' to see the list of users"<<endl;
	}
	void PrintError(){
		cout<<"Error"<<endl;
	}
	
	string GetInput(){
		string str;
		cin>>str;
		return str;
	}
	 void handleEvent(Model& ref);
	 ~View(){};
	 View(){};
	 
};
// ------------------------------------------------------------------

class Users{
public:
	string name;
	int count;
	string has_books[3];
	Users(string str){
	//	has_books = new string[3];
		has_books[0] = "";
		has_books[1] = "";
		has_books[2] = "";
		name = str;
		count = 0;
	}
	Users(){
		has_books[0] = "";
		has_books[1] = "";
		has_books[2] = "";
		count = 0;
	}

};

class Books{
public:
	string title;
	int is_free;
	clock_t time;
	Books(string str){
		title = str;
		is_free = 1;
	}
	Books(){};
};

class Model{
	
    list <IObserver*> _observers;
	list <Books> books;
	list <Users> users;
    
public:
	 string _str;

	Model(){}
	Model(const Model &m){		
		_observers = m._observers;
		books = m.books;
		users = m.users;
		
	}
	Model( View &main_view){
		_str = "Image has been loaded";
		
		add(main_view);
	}
	Model operator=(const Model &m){
		books = m.books;
		users = m.users;
		_observers = m._observers;
	
		return *this;
	}
	
	void PrintBooks();
	void PrintUsers();
		
    void remove(IObserver& ref);
	void add(IObserver& ref);
	void reset(string str);
	void InitBooks();
	void InitUsers(string);
	void _Notify(void);
	const string& get_str();
	void GiveBooks(string);
	void ReturnBooks(string, string );
	void PrintDebtors();
};
