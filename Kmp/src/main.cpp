#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

extern std::vector<int> kmp(const std::string& src, const std::string& pattern);

int main()
{

	std::string src("abababca");
	std::string pattern("abc");
	kmp(src, pattern);

	return 0;
}