#include <iostream>
#include <vector>

extern std::vector<int> manacher(const std::vector<int> &srcVec);
int main()
{
	std::vector<int> vec{13, 13, 13, 11, 4, 11, 13, 1, 11, 12};
	std::cout << "Input Array :" << std::endl;
	for (auto &i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	auto ret = manacher(vec);

	std::cout << "Output Array :" << std::endl;
	for (auto &i : ret)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}