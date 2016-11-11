#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include "model.h"

class Controller{
	Model *model;
	View *view;
	public:
	Controller (){
		//std::cout<<"default"<<std::endl;
	}
	Controller(Model *m, View *v){
		//std::	cout<<"constr"<<std::endl;
		model = m;
		view = v;
	}
	Controller(	const Controller &c){
		model = c.model;
		view = c.view;
	}
	Controller operator=(const Controller &c){
		model = c.model;
		view = c.view;
		return *this;
	}
	
	
	void operate(void);
};
