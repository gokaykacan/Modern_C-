#include <iostream>
#include <thread>
#include <Windows.h>
#include <future>

using namespace std::chrono_literals;

//The operation takes approximately 3 seconds.
int Operation(int count)
{
	
	int sum{};
	for (int i = 0; i < 10; i++)
	{
		sum += i;
		std::cout << ".";
		std::this_thread::sleep_for(300ms);//std::chrono::seconds(1);
	}

	return sum;
}

int main()
{
	std::future<int> result = std::async(std::launch::async, Operation, 10);
	//std::future<int> result = std::async(std::launch::deferred, Operation, 10);
	std::this_thread::sleep_for(1s);
	std::cout << std::endl << "[main]Thread continues..." << std::endl;
	if (result.valid())
	{
		auto timepoint = std::chrono::system_clock::now();
		timepoint += 2s;

		//auto status = result.wait_for(4s);
		auto status = result.wait_until(timepoint);
		switch (status)
		{
			case std::future_status::deferred:
				std::cout << "The task is synchronous" << std::endl;
				break;
			case std::future_status::ready:
				std::cout << "The task is ready" << std::endl;
				break;
			case std::future_status::timeout:
				std::cout << "The tash has not been finished yet" << std::endl;
				break;
		}
		//Operation(10);
		auto sum = result.get(); //smilar to thread.join() // deferred oldugunda senkron cagri olacagýndan, get edilince cagirilir. 
		std::cout << "Sum: " << sum << std::endl;

	}
}