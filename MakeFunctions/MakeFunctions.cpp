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

		//unique_ptr<int> kullanmak ile make_unique kullanmak ayný, bir avantajý yok. make_unique kullanmanýn dezavantajý custom deleter kullanamamak.
		auto p = make_unique<int>(5);
		auto ptr = make_unique<Point>(3, 4);

		//dynamic array icin de kullanilabilir ancak direkt olarak initialize edilemez. Daha sonra edilebilir
		auto pArr = make_unique<int[]>(5);
		pArr[0] = 3;
	}

	{
		//shared_ptr<int> p{ new int[5] };
		
		//make_shared kullanmak shared_ptr<int> kullanmaktan daha avantajlý.
		// new aþamasýnda 1 kere new call yaparak kontrol blok ve kaynak için iþlem yapar
		// ayný þekilde destruct aþamasýnda bir kez delete yaparken hem kontrol blok hem de kaynak delete edilir
		// shared_ptr<int> yaparak yaptýgýmýzda bu farklý.
		// make_shared ile iþlem yaparsak bir çok kez çaðýrýlan new ve delete in önüne geçmiþ oluruz
		// make_shared dynamic arrayler icin, c++20 ile gelmistir.
		auto p = make_shared<int>(5);
		auto ptr = make_shared<Point>(3, 4);

		//Make functions kullanmanýn bir dezavantajý vardýr. O da custom deleter yazamamamýzdýr.
		//Custom deleter kullanmayacaksak make function kullanmamýz önerilir.
	}

	return 0;
}