all: model.o controller.o
	g++ -std=c++11 main.cpp controller.o model.o
model.o: src/model.cpp include/model.h 
	g++ -std=c++11 -c src/model.cpp
controller.o: src/controller.cpp include/controller.h model.o
	g++ -std=c++11 -c src/controller.cpp
