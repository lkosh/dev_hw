#pragma once
#include <iostream>
#include <string>
#include "observer.h"
using namespace std;
using std::string;
class View:public IObserver {
public:
	
	void PrintHelp(){
		cout<<"type 'quit' to exit program"<<endl;
	}
	void PrintError(){
		cout<<"Error"<<endl;
	}
	
	string GetInput(){
		string str;
		cin>>str;
		return str;
	}
};
