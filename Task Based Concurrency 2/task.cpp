#include <iostream>
#include <future>
#include <thread>

using namespace std::chrono_literals;

int Operation(std::promise<int>& data)
{
	auto f = data.get_future();
	std::cout << "[task]Waiting for the count" << std::endl;
	auto count = f.get();
	std::cout << "[task]Count acquired" << std::endl;
	int sum{};
	for (int i = 0; i < count; i++)
	{
		sum += i;
		std::cout << ".";
		std::this_thread::sleep_for(300ms);
	}
	return sum;
}

int main()
{
	std::promise<int> data;
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));

	std::this_thread::sleep_for(1s);
	std::cout << "[main]Setting the data in promise" << std::endl;
	data.set_value(10);

	if (result.valid())
	{
		auto sum = result._Get_value();
		std::cout << "Sum:" << sum << std::endl;
	}
}