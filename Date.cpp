#include<iostream>
#include"Date.h"
#include<stdexcept>
#include <array>
const array< unsigned int, 13>Date::daypermonth{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date(int d, int m, int y) { setdate(d, m, y); }
void Date::setdate(int dd, int mm, int yy) {
	if (yy >= 1900 && yy <= 2100)year = yy;else
	{
		throw invalid_argument{ "year must be from 1900 to 2100" };
	}
	if (mm >= 1 && mm <= 12)month = mm;else
	{
		throw invalid_argument{ "month must be from 1 to 12" };
	}if ((month == 2 && leapyear(year) && dd >= 1 && dd <= 29) || dd >= 1 && dd <= daypermonth[month])day = dd;else
	{
		throw invalid_argument{ "day is out of range for current month and year" };
	}

}
bool Date::leapyear(int y) {
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

bool Date::endOfMonth(int testday)const {
	if (month == 2 && leapyear(year))return testday == 29; else
	{
		return testday == daypermonth[month];
	}
}
void Date::helpincrement()
{
	if (!endOfMonth(day))
	{
		++day;
	}
	else
	{
		if (month < 12) { ++month; day = 1; }
		else
		{
			++year;
			month = 1;
			day = 1;

		}
	}

}
ostream& operator<<(ostream& output, const Date& d) {
	static string monthName[13]{ "", "January", "February",
	"March", "April", "May", "June", "July", "August",
	"September", "October", "November", "December" };
	if (d.month < 1 || d.month > 12)
		throw invalid_argument("Invalid month value");
	output << d.day << "/" << monthName[d.month] << "/" << d.year;
	return output;
}
Date& Date::operator++() { helpincrement(); return *this; }
Date Date::operator++(int t) { Date temp{ *this }; helpincrement(); return temp; }
Date& Date::operator+=(unsigned int additionDays)
{
	for (size_t i = 0; i < additionDays; i++)
	{
		helpincrement();
	}
	return *this;
}
//employee::void printdate(){cout<day}