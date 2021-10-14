#include <iostream>
#include "Integer.h"

using namespace std;

Integer Add(int a, int b)
{
	//Integer temp(a + b);
	//return temp; //named return value optimization

	return Integer(a + b); // return value optimization
}
int main()
{
	cout << "Elision" << endl;

	//Integer a = 3; // copy constructor is called

	Integer b = Add(4, 5); // constructor and then move constructor is called

	return 0;
}