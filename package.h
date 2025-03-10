#include<iostream>
#include<iomanip>
using namespace std;
class package
{
public:
	package(const string& sname, const string& saddress, const string& scity, const string& sstate
		, int sender_ZIP, const string& rname, const string& raddress, const string& rcity,
		const string& rstate, int reciver_Zip, double weight, double cost_per_ounce)
	{
		this->sname = sname;
		this->saddress = saddress;
		this->scity = scity;
		this->sstate = sstate;
		setsenderZIP(sender_ZIP);
		this->rname = rname;
		this->raddress = raddress;
		this->rcity = rcity;
		this->rstate = rstate;
		setreciverZIP(reciver_Zip);
		setcostperounce(cost_per_ounce);
		setWeight(weight);

	}
	virtual	double calulateCost()const {
		return weight * cost_per_ounce;
	}
	double getweigth() const { return weight; }
	double getcostPerOnce()const { return cost_per_ounce; }
	void setWeight(double weight) { this->weight = weight; }
	void setsenderZIP(int sender_ZIP) {
		this->sender_ZIP = sender_ZIP;
	}
	void setreciverZIP(int reciver_Zip) {
		this->reciver_Zip = reciver_Zip;
	}
	void setcostperounce(double cost_per_ounce) {
		if (cost_per_ounce > 0)
			this->cost_per_ounce = cost_per_ounce;
		else
		{
			throw out_of_range{ "negative cost" };
		}
	}
	void info()const
	{
		/*cout << "Sender: " << sname << " | Recipient: " << rname << endl;
		cout << "Weight: " << weight << " oz | Cost per Ounce: $" << cost_per_ounce << endl;*/
		cout << "Sender: " << saddress << " | Recipient: " << raddress << endl;
		cout << "Total Cost: $" << calulateCost() << endl;
	}
private:
	string sname, saddress, scity, sstate,
		rname, raddress, rcity, rstate; int sender_ZIP, reciver_Zip;
	double weight, cost_per_ounce;
};
class twoday :public package
{
public:
	twoday(const string& sname, const string& saddress, const string& scity, const string& sstate
		, int sender_ZIP, const string& rname, const string& raddress, const string& rcity,
		const string& rstate, int reciver_Zip, double weight, double cost_per_ounce, double cost_2_days)
		:package(sname, saddress, scity, sstate, sender_ZIP, rname, raddress,
			rcity, rstate, reciver_Zip, weight, cost_per_ounce)
	{
		this->cost_2_day = cost_2_days;
	}
	double calulateCost() const {
		return	package::calulateCost() + cost_2_day;
	}
private:
	double cost_2_day;
};
class overnight :public package
{
public:
	overnight(const string& sname, const string& saddress, const string& scity, const string& sstate
		, int sender_ZIP, const string& rname, const string& raddress, const string& rcity,
		const string& rstate, int reciver_Zip, double weight, double cost_per_ounce, double addfee)
		:package(sname, saddress, scity, sstate, sender_ZIP, rname, raddress,
			rcity, rstate, reciver_Zip, weight, cost_per_ounce) {
		this->addfee = addfee;
	}
	double calulateCost()const {
		double allcost = getcostPerOnce() + addfee;
		return getweigth() * allcost;

	}
private:
	double addfee;
};
#pragma once
