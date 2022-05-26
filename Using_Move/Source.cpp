#include <iostream>
#include "Integer.h"

void Print(Integer a)
{

}

int main()
{
	Integer a(5);
	a.SetValue(3);

	//auto b(std::move(a));
	//Print(a); //gives compile error since we have closed copy constructor on Integer class
	Print(std::move(a));
	//a.SetValue(7);

	return 0;
}