#include <iostream>
#include "Integer.h"
using namespace std;

/*
* E�er copy constructor kapatl�r ise, kopyalama i�lemini yasaklam�� oluruz. 
* Mesela sadece move constructor tan�mlan�rsa, sadece move yap�l�r, kopyalamaya izin verilmez.
*/
void Number(Integer val)
{
}

int main() {

	auto a = Integer(5);
	a.getValue();
	auto c = a;
	Number(a); //copy constructor �a��r�l�r
	Number(std::move(a)); //move constructor �a��r�l�r

	auto b{ std::move(a) }; //move constructor kapal� iken copy constructor �a��r�l�r
	a.setValue(7);
	a.getValue();

	return 0;
}
