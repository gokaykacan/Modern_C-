#include <iostream>
using namespace std;

class Integer
{
private:
	int* mpInt;
public:
	Integer() 
	{
		mpInt = new int(0);
		cout << "Integer()" << endl;
	}
	Integer(int value)
	{
		mpInt = new int(value);
		cout << "Integer(value)" << endl;
	}
	Integer(const Integer& other) //copy constructor
	{
		cout << "Integer(const Integer& other)" << endl;
		delete mpInt;
		mpInt = new int(*other.mpInt);
	}
	Integer(Integer&& other) // move constructor
	{
		cout << "Integer(Integer&& other)" << endl;
		mpInt = other.mpInt;
		other.mpInt = nullptr;
	}
	Integer& operator=(const Integer& other) //copy assignment
	{
		cout << "operator=(const Integer& other)" << endl;
		if (this == &other)
			return *this;

		delete mpInt;
		mpInt = new int(*other.mpInt);
		return *this;
	}
	Integer& operator=(Integer&& other) //move assignment
	{
		cout << "operator=(const Integer&& other)" << endl;
		if (this == &other)
			return *this;

		delete mpInt;
		mpInt = new int(*other.mpInt);
		other.mpInt = nullptr;

		return *this;
	}
	~Integer()
	{
		cout << "~Integer()" << endl;
		delete mpInt;
	}

	int getValue() const
	{
		return *mpInt;
	}

	void setValue(int value)
	{
		*mpInt = value;
	}
};

Integer Add( Integer& a,  Integer& b)
{
	Integer temp;
	temp.setValue(a.getValue() + b.getValue() );
	return temp;
}

class Number
{
	Integer m_Value{};
public:
	Number(int value) : m_Value{ value } {}

	// bunlardan birini eklemezsem eklemediðimi kullanmaz. 
	//Hiçbirini eklemezsem default olarak hepsini kullanýr.
	Number() = default;
	Number(const Number& other) = default;
	Number(Number&& other) = default;
	Number& operator=(const Number& other) = default;
	Number& operator=(Number&& other) = default;
};

Number CreateNumber(int num)
{
	Number n{ num };
	return n;
}
int main() {

	cout << "Hello Worlddddd !!! " << endl;

	Integer a(5), b(4);

	a.setValue(Add(a, b).getValue() );

	cout << "--------------------" << endl;

	Number n1{ 5 };
	auto n2{ n1 };

	n2 = n1;

	auto n3(CreateNumber(4));
	n3 = CreateNumber(4);

	return 0;
}