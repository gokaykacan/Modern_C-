//============================================================================
// Name        : Singleton.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class SingletenClass
{
	string value;
	static SingletenClass* pInstance;
	SingletenClass(string value) : value(value) {}

public:
	//should not be clonable and assignable
	SingletenClass(SingletenClass& other) = delete;
	void operator=(const SingletenClass& other) = delete;

	static SingletenClass* getInstance(string value)
	{
		if (pInstance == NULL)
		{
			pInstance = new SingletenClass(value);
		}

		return pInstance;
	}
	string getValue()
	{
		return value;
	}
};
SingletenClass* SingletenClass::pInstance = NULL;

int main() {

	cout << SingletenClass::getInstance("value1")->getValue() << endl;
	cout << SingletenClass::getInstance("value2")->getValue() << endl;
	cout << SingletenClass::getInstance("value3")->getValue() << endl;

	return 0;
}
