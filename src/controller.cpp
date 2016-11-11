
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
	string name  = (*view).GetInput();
	(*model).InitBooks();
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
		else 
			(*view).PrintError();
		mes = (*view).GetInput();
	}
		
}
	
