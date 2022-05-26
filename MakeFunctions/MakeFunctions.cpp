#include <iostream>

using namespace std;

class Point
{
public:
	Point(int x, int y)
	{

	}
};

int main()
{
	{
		//unique_ptr<int> p{ new int[5] };

		//unique_ptr<int> kullanmak ile make_unique kullanmak ayn�, bir avantaj� yok. make_unique kullanman�n dezavantaj� custom deleter kullanamamak.
		auto p = make_unique<int>(5);
		auto ptr = make_unique<Point>(3, 4);

		//dynamic array icin de kullanilabilir ancak direkt olarak initialize edilemez. Daha sonra edilebilir
		auto pArr = make_unique<int[]>(5);
		pArr[0] = 3;
	}

	{
		//shared_ptr<int> p{ new int[5] };
		
		//make_shared kullanmak shared_ptr<int> kullanmaktan daha avantajl�.
		// new a�amas�nda 1 kere new call yaparak kontrol blok ve kaynak i�in i�lem yapar
		// ayn� �ekilde destruct a�amas�nda bir kez delete yaparken hem kontrol blok hem de kaynak delete edilir
		// shared_ptr<int> yaparak yapt�g�m�zda bu farkl�.
		// make_shared ile i�lem yaparsak bir �ok kez �a��r�lan new ve delete in �n�ne ge�mi� oluruz
		// make_shared dynamic arrayler icin, c++20 ile gelmistir.
		auto p = make_shared<int>(5);
		auto ptr = make_shared<Point>(3, 4);

		//Make functions kullanman�n bir dezavantaj� vard�r. O da custom deleter yazamamam�zd�r.
		//Custom deleter kullanmayacaksak make function kullanmam�z �nerilir.
	}

	return 0;
}