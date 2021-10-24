#pragma once
#include <iostream>
class Integer {
	int* m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer& obj);
	//Move constructor
	Integer(Integer&& obj);
	//assigment operator overload
	Integer& operator=(const Integer& other);
	// move assignment operator
	Integer& operator=(Integer&& other);
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};
