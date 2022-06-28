#include <iostream>
#include <list>
#include <thread>
#include <mutex>

using namespace std;

const int SIZE = 10000;
list<int> myList;
mutex g_Mutex;

/*
void Download(std::string& file)
{
	for (int i = 0; i < SIZE; ++i)
	{
		g_Mutex.lock();
		myList.push_back(i);
		g_Mutex.unlock();
	}
}

void Download2(std::string& file)
{
	for (int i = 0; i < SIZE; ++i)
	{
		g_Mutex.lock();
		myList.push_back(i);
		g_Mutex.unlock();
	}
}
*/

void Download(std::string& file)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::lock_guard<std::mutex> mtx(g_Mutex);
		if (i == 500)
			return;
		myList.push_back(i);
	}
}

void Download2(std::string& file)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::lock_guard<std::mutex> mtx(g_Mutex);
		myList.push_back(i);
	}
}

int main()
{
	std::string file("file.mp4");
	thread th_Download1(Download, std::ref(file));
	thread th_Download2(Download2, ref(file));

	if (th_Download1.joinable())
		th_Download1.join();
	if (th_Download2.joinable())
		th_Download2.join();

	cout << "List Size: " << myList.size() << endl;

	return 0;
}