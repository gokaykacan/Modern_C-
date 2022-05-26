#include <iostream>
using namespace std;

class Distance
{
	long double m_kilometer;
public:
	Distance(long double kilometer) : m_kilometer(kilometer) {}
	void setValue(long double kilometer)
	{
		m_kilometer = kilometer;
	}
	long double getValue()
	{
		return m_kilometer;
	}
};

//Literals operator should be global, cannot be member function
//Literals operators can only be:
//unsigned long long
//double long
//const char*
//char
Distance operator"" _mi(long double value)
{
	return Distance{ 1.6 * value };
}

Distance operator"" _meter(long double value)
{
	return Distance{ 1000 * value };
}

int main()
{
	Distance d1{ 20 };

	cout << "Distance in kilometer: " << d1.getValue() << endl;

	Distance d2{ 20.0_mi };
	cout << "Distance in kilometer: " << d2.getValue() << endl;

	Distance d3{ 20.0_meter };
	cout << "Distance in meter: " << d3.getValue() << endl;

	return 0;
}