#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

extern void card_pick(int totalNum, int pickNum, std::vector<std::vector<bool>> &output);

int main()
{

	std::vector<std::vector<bool>> ret;
	card_pick(6, 3, ret);

	for (auto &v : ret)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i])
			{
				std::cout << i << " ";
			}
		}
		std::cout << std::endl;
	}

	return 0;
}