#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

extern int quik_sort(std::vector<int> &vec);

int main()
{
	std::vector<int> vec;

	std::cout << "Before QuikSort : \n";
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int value = rand() % 100;
		std::cout << value << " ";
		vec.push_back(value);
	}
	std::cout << std::endl;

	quik_sort(vec);
	std::cout << "After QuikSort : \n";
	for (auto &v : vec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return 0;
}