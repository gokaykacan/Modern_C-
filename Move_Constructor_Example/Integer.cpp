#include "Integer.h"
using namespace std;

Integer::Integer()
{
	cout << "Integer()" << endl;
	m_ptr = new int(0);
}

Integer::Integer(int value)
{
	cout << "Integer(int value)" << endl;
	m_ptr = new int(value);
}

Integer::Integer(const Integer& other)
{
	cout << "Integer(const Integer& other)" << endl;
	m_ptr = new int(*other.m_ptr);
}

Integer& Integer::operator=(const Integer& other)
{
	cout << "operator=(const Integer& other)" << endl;
	if (this == &other)
		return *this;

	delete m_ptr;
	m_ptr = new int(*other.m_ptr);

	return *this;
}

Integer::Integer(Integer&& other)
{
	cout << "Integer(Integer&& other)" << endl;
	m_ptr = other.m_ptr;
	other.m_ptr = nullptr;
}

Integer& Integer::operator=(Integer&& other)
{
	cout << "operator=(Integer&& other)" << endl;
	if (this == &other)
		return *this;

	delete m_ptr;
	m_ptr = new int(*other.m_ptr);
	other.m_ptr = nullptr;

	return *this;
}

Integer::~Integer()
{
	cout << "~Integer()" << endl;
	delete m_ptr;
}

int Integer::getValue()
{
	cout << "Value: " << *m_ptr << endl;
	return *m_ptr;
}

void Integer::setValue(int value)
{
	//if (m_ptr == nullptr)
	//	m_ptr = new int(value);
	//else
		*m_ptr = value;

}
