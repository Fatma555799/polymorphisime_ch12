#include<iostream>
#include<sstream>
#include<iomanip>
#include"employee.h"
#include<vector>
#include<typeinfo>
#include<ctime>
#include"package.h"
#include"carpon foot print.h"
//confirm there work with pointer and refrence
void virtualptr(const employee* eptr) { cout << eptr->info() << endl; }
void virtualref(const employee& eref) { cout << eref.info() << endl; }
using namespace std;

	
void main()
{
	car c{ 500,1000 };
	building b{ 300,800 };
	bicycle bi{ false };
	vector<carponFoorPrint*>ca{ &c,&b,&bi };
	for (carponFoorPrint* cp:ca)
	{
		car* c = dynamic_cast<car*>(cp);
		building* b = dynamic_cast<building*>(cp);
		bicycle* bi = dynamic_cast<bicycle*>(cp);
		if (c != nullptr) {  c->info(); }
		if (b != nullptr) { b->info(); }
		if (bi != nullptr) { bi->info(); }
		cout <<"carpon foot print : "<<cp->getCarponFootPrint() << endl;

 	}
	//time_t now = time(0);
	//struct tm localTime;
	//localtime_s(&localTime, &now);
	//int currentMonth = localTime.tm_mon + 1;
	////static binding
	//cout << "STATIC BINDING" << endl;
	//salared s1{ "merfat","ahmed","333-000-888",9000,5,3,1990 };
	//cout << s1.info() << endl;
	//commicionem e1{ "fatma","usame","555-343-4334",1000,0.06,23,7,2005 };
	//cout << e1.info() << endl;
	//base_salaried_commission b1{ "nada","usama","343-434-545",2000,0.09,1000,21,11,2007 };
	//cout << b1.info() << endl;
	//pieceWorker pe{ "sara","salama" , "999-000-777",5,100,6,7,2002 };
	//hoursworker h{ "menna","gamal","002-882-732",10,30,4,5,2005 };
	//hoursworker g{ "gnan","ahmed","002-882-732",10,40,4,3,2010 };
	////dynamic binding by vector
	//vector<employee*>employees{ &s1,&e1,&b1,&pe,&h,&g };
	//cout << "VIRTUl CALLS DYNAMIC BININDG" << endl;
	//cout << "BY POINTER" << endl;
	//for (employee* e : employees)
	//{
	//	virtualptr(e);
	//	base_salaried_commission* derivedptr = dynamic_cast<base_salaried_commission*>(e);
	//	if (derivedptr != nullptr) {
	//		double oldsalary = derivedptr->getbasesalessalary();
	//		cout << "old salary is " << oldsalary << endl;
	//		derivedptr->setbasedsalary(oldsalary * 1.10);
	//		cout << "new salary with reward 10% : " << derivedptr->getbasesalessalary() << endl;
	//		cout << "new earning " << e->earning() << endl;
	//	}
	//	if (currentMonth == e->getmonth()) { double salary = e->earning(); salary += 1000; cout << "HAPPY BBITRHTDAY!!!!!! here it your bonous $" << salary << endl; }
	//}
	//cout << endl << endl;
	/*for (const employee* e : employees)
	{
		virtualref(*e);
	}*/
	/*package p("fatma", "ban", "mansoura", "egypt", 2323,
		"sara", "DD", "Doha", "quatr", 3443, 30, 3);
	twoday twoDayPackage("Alice", "123 Street", "New York", "NY", 10001,
		"Bob", "456 Avenue", "Los Angeles", "CA", 90001,
		8.0, 0.5, 2.0);
	overnight overnightPackage("Alice", "123 Street", "New York", "NY", 10001,
		"Bob", "456 Avenue", "Los Angeles", "CA", 90001,
		8.0, 0.5, 0.2);
	cout << "-----------------------------\n";
	double total=0;
	vector<package*>packages{ &twoDayPackage, &overnightPackage };
	for ( package* p:packages)
	{
		p->info();
		total += p->calulateCost();

	}
	cout << "all cost: " << total << endl;
}*/
}
