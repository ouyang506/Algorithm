#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

extern std::vector<int> kmp(const std::string &src, const std::string &pattern);

int main()
{
	std::string src("bbabcgabcgabcga");
	std::string pattern("abcgab");
	auto ret = kmp(src, pattern);

	std::cout << "Source String :" << src << std::endl;
	std::cout << "Pattern String :" << pattern << std::endl;

	std::cout << "All Pattern Match :\n";
	for (auto &index : ret)
	{
		std::cout << index << " ";
	}
	std::cout << std::endl;

	return 0;
}