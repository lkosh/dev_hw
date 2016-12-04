
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <limits>
#include "../include/controller.h"

//#include "view.h"
#include "../include/model.h"
using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::tuple;
using std::vector;

void Controller::operate(void){
	(*model)._str = "Please enter your name";
	(*model)._Notify();
	string name  = (*view).GetInput();
	(*model)._str = "Please choose type of source - 1,2 or 3";
	(*model)._Notify();
	string type = (*view).GetInput();
	
	(*model).InitBooks(type);
	(*model).InitUsers(name);
	(*view).PrintHelp();
	string mes;
	
	mes = (*view).GetInput();
	
	while ( mes != "quit"){
		if (mes == "help")
			(*view).PrintHelp();
		else if (mes == "users")
			(*model).PrintUsers();
		else if (mes == "books"){
			(*model).PrintBooks();
		}
		else if (mes == "get")
			(*model).GiveBooks(name);
		else if (mes == "return"){
			string title = (*view).GetInput();
			(*model).ReturnBooks(name, title);
		}
		else if (mes == "print_debts")
			(*model).PrintDebtors();
		else if (mes == "login"){
			name = (* view).GetInput();
			(*model).AddUser(name);
		}
		else 
			(*view).PrintError();
		mes = (*view).GetInput();
	}
		
}
	
