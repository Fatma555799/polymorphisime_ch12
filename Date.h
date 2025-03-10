#include<iostream>
#include<array>
#include<sstream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream&, const Date&);
	//friend void printdate();

public:
	Date(int d = 1, int m = 1, int y = 1900);
	void setdate(int, int, int);
	Date& operator++();
	Date operator++(int);
	Date& operator+=(unsigned int);
	static bool leapyear(int);
	bool endOfMonth(int)const;
	int getday()const { return day; }
	int getmont()const { return month; }
	int getyear()const { return year; }
private:
	int day;int month; int year;
	static const array<unsigned int, 13>daypermonth;
	void helpincrement();
};

