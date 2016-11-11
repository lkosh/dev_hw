#include "../include/model.h"
#include <string>
#include <math.h>
#include <limits>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>
#include <cfloat>
#include <time.h>
#include <stdlib.h>
//#include "view.h"
#include <list>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::list;
using std::vector;
using namespace std;

//-----------------------VIEW---------------------------------
void View::handleEvent(  Model &ref)
  {
	
      cout  << ref.get_str() << endl;
  }
//------------------------------------------
void Model::_Notify(void)
    {	//cout<<"Notify"<<endl;
		
        for(auto iter : _observers)
        {
			
            iter->handleEvent(*this);
            
        }
    }
    
void Model::add(IObserver& ref){
        _observers.push_back(&ref);
    }

void Model::remove(IObserver& ref){
        _observers.remove(&ref);
    }
    
 const string& Model::get_str() 
    {
        return _str;
    }

void Model::reset(string str)
    {
        _str = str;
        _Notify();
    }


void Model::PrintUsers(){
	for (auto iter: users){
		_str = iter.name;
		_Notify();
	}
}

void Model::PrintBooks(){
	_str = "the following books are available: ";
	_Notify();
	for (auto iter: books){
		if (iter.is_free){
			_str = iter.title;
			_Notify();
			
		}
	}
}

void Model::InitBooks(){
	Books b("Book1");
	books.push_back(b);
	Books a("Book2");
	books.push_back(a);
	
}

void Model::InitUsers(string name){
	Users u(name);
	users.push_back(u);
}
	// how do we initiate books though
void Model::GiveBooks(string name){
	_str = "Enter title";
	_Notify();
	string mes;
	for (auto iter: _observers){
		//mes = iter->GetInput();
		cin>>mes;
	}
	list<Users>::iterator iter2;
	for ( iter2 = users.begin(); iter2 != users.end(); ++iter2){
		if ((*iter2).name == name){
			if ((*iter2).count == 3){
				_str = "You can't have more then 3 books";
				_Notify();
				return;
			}
			break;
		}
	}
	list<Books>::iterator iter;
	for ( iter = books.begin(); iter != books.end(); ++iter){
		if ((*iter).title == mes){
			if ((*iter).is_free == 0){
				_str = "Sorry, this books is already taken";
				_Notify();
				return;
			}
			(*iter).is_free = 0;
			(*iter).time = clock();
			_str = "Book Found";
			_Notify();
			
			(*iter2).count += 1;
			
			(*iter2).has_books[(*iter2).count - 1 ] = (*iter).title;
			_str = "Book given";
			_Notify();
			
			return;
		}
	}
	_str = "Wrong book title";
	_Notify();
	
}
		
void Model::ReturnBooks(string name, string title){
	list<Users>::iterator iter2;
	for ( iter2 = users.begin(); iter2 != users.end(); ++iter2){
		if ((*iter2).name == name){
			for (int i = 0 ; i < (*iter2).count; i ++){
				if ((*iter2).has_books[i] == title){
					_str = "Book found and returned";
					_Notify();
					(*iter2).count --;
					if (i == 1){
						(*iter2).has_books[i] = (*iter2).has_books[i+1];
						(*iter2).has_books[i+1] = "";
					}
					else if (i == 0){
						(*iter2).has_books[i]= (*iter2).has_books[i+1];
						(*iter2).has_books[i+1] = (*iter2).has_books[i+2];
						(*iter2).has_books[i+2] = "";
					}
				}
				
			}
		}
	}
	
	list<Books>::iterator iter;
	for ( iter = books.begin(); iter != books.end(); ++iter){
			if ((*iter).title == title){
				(*iter).is_free = 1;
				(*iter).time =0;
			}
	}
}

void Model::PrintDebtors(){
	list<Users>::iterator iter2;
	_str = "The following people haven't returned their books in time:";
	_Notify();
	for ( iter2 = users.begin(); iter2 != users.end() ; ++iter2){
		int is_debtor = 0;
		for (int i = 0 ; i < (*iter2).count && !is_debtor; i ++){
			string t = (*iter2).has_books[i];
			list<Books>::iterator iter;
			for ( iter = books.begin(); iter != books.end(); ++iter){
				if ((*iter).title == t){
					clock_t c = clock();
					double tmp =  (c - (*iter).time) / CLOCKS_PER_SEC;
					is_debtor = tmp > (3600*24*31);
				}
			}
		}
		if (is_debtor){
			_str = (*iter2).name;
			_Notify();
		}
	}
}
