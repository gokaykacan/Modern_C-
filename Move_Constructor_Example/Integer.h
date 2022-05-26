#pragma once
#include <iostream>

class Integer {
	int* m_ptr;

public:
	Integer();
	Integer(int value);
	Integer(const Integer& other); //copy constructor
	Integer& operator=(const Integer& other); // copy assignment
	Integer(Integer&& other);//move consturctor
	Integer& operator=(Integer&& other); //move assignment
	~Integer();
	int getValue();
	void setValue(int value);
};
