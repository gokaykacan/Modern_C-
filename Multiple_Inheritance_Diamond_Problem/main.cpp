#include <iostream>

using namespace std;

/*
*				Vehicle
*				/		\
*			Car			Truck
*				\		/
*				Renault
*/
class Vehicle
{
	string mName;
public:
	Vehicle(string name): mName(name)
	{
		cout << "Vehicle Constructor" << endl;
	}
	~Vehicle()
	{
		cout << "~Vehicle Destructor" << endl;
	}
	const string &getName()
	{
		return "Vehicle GetName():" + mName;
	}
};

class Car : virtual public Vehicle
{
public:
	Car(string name): Vehicle(name)
	{
		cout << "Car Constructor" << endl;
	}
	~Car()
	{
		cout << "~Car Destructor" << endl;
	}
};

class Truck : virtual public Vehicle
{
public:
	Truck(string name): Vehicle(name)
	{
		cout << "Truck Constructor" << endl;
	}
	~Truck()
	{
		cout << "~Truck Destructor" << endl;
	}
};

class Renault : public Car, public Truck
{
public:
	//using Car::getName;
	Renault(string name): Car(name), Truck(name), Vehicle(name)
	{
		cout << "Renault Constructor" << endl;
	}
	~Renault()
	{
		cout << "~Renault Destructor" << endl;
	}
};

int main()
{
	//Renault r;
	//Vehicle* s = &r;
	//cout << s->getName() << endl;

	Renault r("renaulttttt");
	cout << r.getName() << endl;


	return 0;
}