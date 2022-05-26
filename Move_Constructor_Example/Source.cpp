#include <iostream>
#include "Integer.h"
using namespace std;

/*
* Eðer copy constructor kapatlýr ise, kopyalama iþlemini yasaklamýþ oluruz. 
* Mesela sadece move constructor tanýmlanýrsa, sadece move yapýlýr, kopyalamaya izin verilmez.
*/
void Number(Integer val)
{
}

int main() {

	auto a = Integer(5);
	a.getValue();
	auto c = a;
	Number(a); //copy constructor çaðýrýlýr
	Number(std::move(a)); //move constructor çaðýrýlýr

	auto b{ std::move(a) }; //move constructor kapalý iken copy constructor çaðýrýlýr
	a.setValue(7);
	a.getValue();

	return 0;
}
