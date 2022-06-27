#include <iostream>

//Sort the array
template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp) 
{
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (comp(arr[j], arr[j + 1])) {
				T temp = std::move(arr[j]);
				arr[j] = std::move(arr[j + 1]);
				arr[j + 1] = std::move(temp);
			}
		}
	}
}

//Find the max number of the array
template<typename T, int size, typename Max>
int MaxNumber(T(&arr)[size], Max max)
{
	int _max = arr[0];
	for (int i = 1; i < size-1; i++)
	{
		if (_max < max(arr[i], arr[i + 1]))
			_max = max(arr[i], arr[i + 1]);
	}
	return _max;
}

bool Comp(int x, int y) {
	return x > y;
}
bool Comp1(int x, int y) {
	return x < y;
}
struct Comp2 {
	bool operator()(int x, int y) {
		return x > y;
	}
};

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation) {
	for (int i = 0; i < size - 1; ++i) {
		operation(arr[i]);
	}
}
template<typename T>
struct __Unnamed {
	int offset;
	__Unnamed(int off) :offset(off) {

	}
	void operator()(T& x) {
		x += offset;
		++offset;
	}
};
class Product {
	std::string name;
	float price;
public:
	Product(const std::string& n, float p) :name(n), price(p) {

	}
	void AssignFinalPrice() {
		float taxes[]{ 12, 5, 5 };
		float basePrice{ price };
		//Capture this
		ForEach(taxes, [basePrice, this](float tax) {
			float taxedPrice = basePrice * tax / 100;
			price += taxedPrice;
			});
	}
	float GetPrice()const {
		return price;
	}
};
int main() {

	atexit([]() {
		std::cout << "Program is exitting..." << std::endl;
		});
	/*Product p{ "Watch", 500 };
	p.AssignFinalPrice();
	std::cout << p.GetPrice() << std::endl;*/

	//Lambda within a lambda
	[](int x) {
		x *= 2;
		[](int x) {
			std::cout << x << std::endl;
		}(x);
	}(5);


	__Unnamed<int> n(3);
	int x = 5;
	n(x);


	int arr[]{ 1,6,8,4,0 };
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	std::cout << std::endl;

	//max number:
	auto _max = [](auto x, auto y)
	{
		return x>y ? x:y;
	};

	std::cout << "Max: " << MaxNumber(arr, _max) << std::endl;
	//

	int offset = 0;
	/*ForEach(arr, [offset](auto &x) {
		x += offset;
	});*/

	//ForEach(arr, [offset](auto &x)mutable {
	//	x += offset;
	//	++offset;
	//});

	int sum{};
	ForEach(arr, [&, offset](auto& x) {
		sum += x;
		});
	std::cout << "Sum:" << sum << std::endl;
	ForEach(arr, [](auto x) {
		std::cout << x << " ";
		});
	std::cout << std::endl;

	return 0;
}

void OldCode() {
	int arr[]{ 1,6,8,4,0 };
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	auto comp = [](auto x, auto y) {
		return x > y;
	};
	Sort(arr, comp);
	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}