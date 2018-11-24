#include <vector>
#include <iostream>

//pattern和自己比较预处理，确定不匹配时已经匹配的串可以向右移动的距离
//这里返回的是前缀与后缀的最大匹配长度
std::vector<int> kmpMakeNext(const std::string &pattern)
{
	std::vector<int> nextVec((int)pattern.length() + 1, 0);
	nextVec[0] = -1;
	nextVec[1] = 0;

	for (int i = 2; i <= (int)pattern.length(); ++i)
	{
		for (auto j = i - 1; j >= 1; --j)
		{
			if (pattern.at(nextVec[j]) == pattern.at(i - 1))
			{
				nextVec[i] = nextVec[j] + 1;
				break;
			}
		}
	}

	std::cout << "print next value : \n";
	for (auto &v : nextVec)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	return nextVec;
}

std::vector<int> kmp(const std::string &src, const std::string &pattern)
{
	std::vector<int> ret;
	if (src.empty() || pattern.empty() || src.size() < pattern.size())
	{
		return ret;
	}

	auto nextVec = kmpMakeNext(pattern);
	int patternLen = (int)pattern.length();
	int i = 0;
	int j = 0;

	while (i < (int)src.length())
	{
		if (src.at(i) == pattern[j])
		{
			++i;
			++j;
			if (j == patternLen)
			{
				//match all pattern
				ret.push_back(i - patternLen);
				j = nextVec[j];
			}
		}
		else
		{
			++i;
			int nextVal = nextVec[j];
			if (nextVal > 0)
			{
				j = nextVal;
			}
			else
			{
				j = 0;
			}
		}
	}

	return ret;
}
