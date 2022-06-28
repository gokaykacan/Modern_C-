#include <iostream>
#include <thread>
#include <list>
#include <string>

const int SIZE = 10000000;
std::list<int> myList;

class String
{
public:
	String()
	{
		std::cout << "String() constructor " << std::endl;
	}
	String(const String&)
	{
		std::cout << "String(const String&) constructor" << std::endl;
	}
	String& operator=(const String&)
	{
		std::cout << "String& operator=(const String&)" << std::endl;

		return *this;
	}
	~String()
	{
		std::cout << "~String() deconstructor" << std::endl;
	}
};
void Downloader(const String &file)
{
	std::cout << "[Downloader] is started" << std::endl;
	for (int i=0; i<SIZE; i++)
	{
		myList.push_back(i);
	}
	std::cout << "[Downloader] is ended" << std::endl;
}
int main()
{
	String file;
	std::cout << "[main]User has started an operation" << std::endl;

	std::thread thDownloader(Downloader, std::cref(file)); //for non-const ref, use std::ref

	std::cout << "[main]User has started another operation" << std::endl;

	if (thDownloader.joinable())
	{
		thDownloader.join();
	}

	return 0;
}