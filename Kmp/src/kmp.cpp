#include <vector>
#include <iostream>

//pattern和自己比较预处理，确定不匹配时已经匹配的串可以向右移动的距离
//这里返回的是前缀与后缀的最大匹配长度
std::vector<int> kmpMakeNext(const std::string& pattern)
{
	std::vector<int> nextVec{ pattern.length(), 0};
	nextVec[0] = -1;
	int curNext = nextVec[0];

	for (int i = 1; i < pattern.length(); ++i)
	{
		if (i == 1)
		{
			++curNext;
		}



	}

	return nextVec;
}

std::vector<int> kmp(const std::string& src, const std::string& pattern)
{

	std::vector<int> ret;
	if (src.empty() || pattern.empty() || src.size() < pattern.size())
	{
		return ret;
	}

	return ret;
}
