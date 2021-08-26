#include <iostream>
using namespace std;

class Car
{
public:
	virtual void getDetails()
	{
		cout << "Total no of Car Brands: 2" << endl;
	}
};

class Honda: public Car
{
public:
	void getDetails()
	{
		cout << "Total no of Car Models: 5" << endl;
	}
};

class Toyota: public Car
{
public:
	virtual void getEngineInfo() = 0;
};

class CHR: public Toyota
{
public:
	void getEngineInfo()
	{
		cout << "CHR Engine Capacity: 1500 CC" << endl;
	}
};

class Prius: public Toyota
{
public:

};

int main()
{
	Car c1; // Can instantiate base class with virtual function
	c1.getDetails();

	Honda h1;
	Car* c2;
	c2 = &h1;
	c2->getDetails();

	CHR m1;
	//Toyota t1; // Can not instantiate abstract class with pure virtual function
	Toyota* t2;
	t2 = &m1;
	t2->getEngineInfo();

	//Prius m2; // Abstract class

	return 0;
}