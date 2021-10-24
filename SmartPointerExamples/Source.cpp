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
	Display(p.get()); // Display(p) unique pointer verdiðimiz için çalýþmaz, Integer pointer istiyor. Bu durumda get fonksiyonu istediðimizi yapar
	//p = nullptr; // unique pointer assignment operator e izin veriyor. Bu statemant aslýnda pointer ý delete edip null a eþitler

	p.reset(new Integer{});
	*p = __LINE__;
	Display(p.get());

	//Store(p); // çalýþmaz, unique pointerýn kopyasýný tutamayýz.
	Store2(p); // referans olarak geçirebiliriz
	Store(std::move(p)); // move çalýþýr


	// delete etmemize gerek yok, smart pointer kullandýk.
}
int main()
{
	Operate(20);

	return 0;
}