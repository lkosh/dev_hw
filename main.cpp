#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <limits>
#include "include/controller.h"
//#include "view.h"
#include "include/model.h"
using std::string;
using std::stringstream;
using std::cout;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::tuple;


int main(int argc, char **argv){
	View m_view;
	Model m_model(m_view);
	
	Controller main_controller(&m_model, &m_view);
	//m_model._Notify();
	main_controller.operate();
	return 0;
}
