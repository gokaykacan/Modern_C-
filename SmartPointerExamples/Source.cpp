#include "Integer.h"
#include <iostream>
#include <memory>

Integer* GetPointer(int value)
{
	Integer* p = new Integer{ value };
	return p;
}

void Display(Integer* p)
{
	std::cout << p->GetValue() << std::endl;
}

void Store(std::unique_ptr<Integer> p)
{
	std::cout << "Storing1 data: " << p->GetValue() << std::endl;
}

void Store2(std::unique_ptr<Integer> &p)
{
	std::cout << "Storing2 data: " << p->GetValue() << std::endl;
}

void Operate(int value)
{
	std::unique_ptr<Integer> p{ GetPointer(value) };
	if (p == nullptr)
	{
		p.reset(new Integer(value));
	}

	p->SetValue(234);
	Display(p.get()); // Display(p) unique pointer verdi�imiz i�in �al��maz, Integer pointer istiyor. Bu durumda get fonksiyonu istedi�imizi yapar
	//p = nullptr; // unique pointer assignment operator e izin veriyor. Bu statemant asl�nda pointer � delete edip null a e�itler

	p.reset(new Integer{});
	*p = __LINE__;
	Display(p.get());

	//Store(p); // �al��maz, unique pointer�n kopyas�n� tutamay�z.
	Store2(p); // referans olarak ge�irebiliriz
	Store(std::move(p)); // move �al���r


	// delete etmemize gerek yok, smart pointer kulland�k.
}
int main()
{
	Operate(20);

	return 0;
}