#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

extern void quik_sort(std::vector<int> &vec, int start, int end);

int main()
{
	std::vector<int> vec;

	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int value = rand() % 10;
		vec.push_back(value);
	}

	std::cout << "Before QuikSort : \n";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	quik_sort(vec, 0, vec.size() - 1);

	std::cout << "After QuikSort : \n";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}