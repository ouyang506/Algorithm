#include <vector>
#include <iostream>

void dfs_pick(int needPick, int hasPick, int pos, std::vector<bool> mark, std::vector<std::vector<bool>> &output)
{
  auto left = mark.size() - pos;

  if (left == needPick - hasPick)
  {
    for (int i = pos; i < mark.size(); ++i)
    {
      mark[i] = true;
    }
    hasPick = needPick;
  }

  if (hasPick == needPick)
  {
    output.push_back(mark);
    return;
  }

  mark[pos] = true;
  dfs_pick(needPick, hasPick + 1, pos + 1, mark, output);

  mark[pos] = false;
  dfs_pick(needPick, hasPick, pos + 1, mark, output);
}

void card_pick(int totalNum, int pickNum, std::vector<std::vector<bool>> &output)
{
  std::vector<bool> mark(totalNum, false);
  dfs_pick(pickNum, 0, 0, mark, output);
}
