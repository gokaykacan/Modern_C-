#include <iostream>

using namespace std;

int main()
{
	//default deleter of unique pointer will call delete, not delete all arrays.
	//This might lead to undefined behaviour
	unique_ptr<int> arr{ new int[5]{1,2,3,4,5} };

	//bu sekilde kullanmaya izin vermiyor
	arr[0] = 9;

	//bu sekilde kullanmamiz gerekir.
	arr.get()[0] = 9;


	//C++17'de gelen asagidaki tanim ile problem yok (c++11 ve 14'te yok)
	unique_ptr<int[]> arr2{new int[5]{1,2,3,4,5}};

	//bu sekilde kullanmaya izin verir
	arr2[0] = 9;

	return 0;
}