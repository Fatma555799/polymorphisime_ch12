#include<iostream>
#include<sstream>
#include<iomanip>
#include"Date.h"
using namespace std;
class employee
{
public:
	//friend void printdate();
	employee(const string& f, const string& l, const string& ssn,int d,int m,int y) {
	setfirstname(f);
	setlastname(l);
	setssn(ssn);
	birthday.setdate(d, m, y);
}
	int getmonth() { return birthday.getmont(); }
	  void setfirstname(const string f) { firstname = f; }
	  void setlastname(const string l) { lastname = l; }
	  void setssn(const string ssn) { this->ssn = ssn; }
	  string getfirstname()const { return firstname; }
	  string getlastname()const { return lastname; }
	  string getssn()const { return ssn; }
	  virtual double earning() const = 0;
	  virtual  string info() const {
		  ostringstream output;
		  output << setprecision(2) << fixed;
		  output << "first name " << getfirstname() << "\n last name " << getlastname() << "\n ssn " << getssn() << "\nbirth day"<<birthday.getday()<<"/"<< birthday.getmont() << "/"<< birthday.getyear();
		  return output.str();
	  }
	  virtual ~employee() = default;
protected:
	string firstname;
	string lastname;
	string ssn;
	Date birthday;
};
class salared :public employee
{
public:
	salared(const string& f, const string& l, const string& ssn, double salary,int d,int m,int y) :employee(f, l, ssn,d,m,y) { setSalary(salary); }
	void setSalary(const double s) { if (s >= 0) salary = s; }
	double getSalary()const { return salary; }
	double earning() const override { return getSalary(); }
	virtual	string info() const override {
		ostringstream output;
		output << setprecision(2) << fixed;
		output << employee::info() << "\n earning " << earning() << "\nsalary " << getSalary() << endl;
		return output.str();
	}
	~salared()
	{
		cout << "salared constructor" << endl;
	}
private:
	double salary;
};
class commicionem :public employee
{
public:
	commicionem(const string& f, const string& l, const string& ssn, double sales , double p , int d, int m, int y) :employee(f, l, ssn,d,m,y) {
		setsalessalary(sales);
		setprecentage(p);
	}
	void setsalessalary(const double s) { if (s >= 0.0) salesSalary = s; }
	void setprecentage(const double p) { if (p >= 0.0 && p < 1) precentage = p; }
	double getsalessalary() const { return salesSalary; }
	double getprecentage()const { return precentage; }
	virtual	double earning()const { return getsalessalary() * getprecentage(); }
	virtual	string info() const override {
		ostringstream output;
		output << setprecision(2) << fixed;
		output << employee::info() << "\ngross sales " << getsalessalary() << "\nprecentag " << getprecentage() << "\n earning" << earning();
		return output.str();
	}
	virtual ~commicionem()
	{
		cout << "comminconem destructor" << endl;
	}
protected:
	double salesSalary;
	double precentage;
};

class base_salaried_commission :public commicionem
{
public:
	base_salaried_commission(const string& f, const string& l, const string& ssn, double sales , double p , double base , int d, int m, int y) :commicionem(f, l, ssn, sales, p,d,m,y) { setbasedsalary(base); }
	void setbasedsalary(double bs) { based_salary = bs; }
	double getbasesalessalary() const { return based_salary; }
	virtual double earning()const override {
		return (/*getsalessalary() * getprecentage()*/commicionem::earning() + getbasesalessalary());
	}
	virtual	string info() const override {
		ostringstream output;
		output << setprecision(2) << fixed;
		output << commicionem::info() << "\nbase salary" << getbasesalessalary();
		return output.str();

	}
	~base_salaried_commission()
	{
		cout << "base salary destructor" << endl;
	}
private:
	double based_salary;
};
class pieceWorker:public employee
{
public:
	pieceWorker(const string& f, const string& l, const string& ssn,double wage, double piece, int d, int m, int y) : employee(f, l, ssn, d, m, y)
	{
		setWage(wage);
		setPiece(piece);
	}
	~pieceWorker(){
		cout << "piece constructor" << endl;
	}
	void setWage(const double s) { if (s >= 0) wage = s; }
	double getWage()const { return wage; }
	void setPiece(const double s) { if (s >= 0) piece = s; }
	double getPiece()const { return piece; }
	double earning() const override { return getPiece() * getWage(); }
	virtual	string info() const override {
		ostringstream output;
		output << setprecision(2) << fixed;
		output << employee::info() << "\nwage for piece " << getWage() << "\npieces " << getPiece() << "\n earning" << earning();
		return output.str();
	}
private:
	double piece;
	double wage;
};
class hoursworker :public employee
{
public:
	hoursworker(const string& f, const string& l, const string& ssn, double wage, double hours, int d, int m, int y) : employee(f, l, ssn, d, m, y)
	{
		setWage(wage);
		setHours(hours);
	}
	~hoursworker() {
		cout << "hours constructor" << endl;
	}
	void setWage(const double s) { if (s >= 0) wage = s; }
	double getWage()const { return wage; }
	void setHours(const double s) { if (s >= 0) hours = s; }
	double getHours()const { return hours; }
	double earning() const override
	{
		double all = (getHours() >= 40 ? getHours() * 1.50 : getHours()) * getWage();
		return all;
	}
	virtual	string info() const override {
		ostringstream output;
		output << setprecision(2) << fixed;
		output << employee::info() << "\nwage for piece " << getWage() << "\n hours " << getHours() << "\n earning" << earning();
		return output.str();
	}
private:
	double hours;
	double wage;
};


