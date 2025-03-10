#include<iostream>
#include<array>
#include<sstream>
using namespace std;
class carponFoorPrint
{
public:
	virtual double getCarponFootPrint() = 0;
private:

};
class car:public carponFoorPrint
{
public:
	car(double s = 100, double feulperyear=0) :speed(s) { this->feulPerYear = feulperyear; }
	double getCarponFootPrint()override{
		return(feulPerYear * co2foronegalon);
	}
	void info() { cout << "speed of car " << speed <<"\nfeul per year"<<feulPerYear << endl; }

private:
	double speed;
	double feulPerYear;
	double co2foronegalon = 20;
};
class building:public carponFoorPrint
{
public:
	building(double h = 100, double n = 0) :highet{h}, naturalGas{n} {}
	void info() { cout << "highet of buliding " << highet <<"\nnatural gas per year "<<naturalGas << endl; }
	double getCarponFootPrint()override {
		return(naturalGas * co2perone);
	}

private:
	double highet;
	double naturalGas;
	double co2perone = 10;
};
class bicycle:public carponFoorPrint
{
public:
	bicycle(bool c=1) :ring(c) {}
	void info() { cout<< "ring: " <<boolalpha<< ring << endl; }
	double getCarponFootPrint() override{
		return 0;
	}
private:
	bool ring;
};