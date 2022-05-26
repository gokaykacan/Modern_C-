#include <iostream>
using namespace std;

struct Free {
	void operator()(int* p)
	{
		free(p);
		cout << "Pointer has been released!" << endl;
	}
};

void MallocFree(int* p)
{
	free(p);
	cout << "Pointer released!" << endl;
}
void UniquePointerDeleter()
{
	//unique_ptr<int, Free> p{ (int*)malloc(4), Free{} };
	unique_ptr<int, void (*)(int*)> p{ (int*)malloc(4), MallocFree };
	*p = 124;
	cout << "Pointer Value: " << *p << endl;
}

void SharedPointerDeleter()
{
	//shared_ptr<int> p{ (int*)malloc(4), Free{} };
	shared_ptr<int> p{ (int*)malloc(4), MallocFree };
	*p = 124;
	cout << "Pointer Value: " << *p << endl;
}

int main()
{
	//UniquePointerDeleter();
	SharedPointerDeleter();
	return 0;
}

