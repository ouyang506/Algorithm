#include <vector>
#include <assert.h>

void quik_sort(std::vector<int> &vec, int start, int end)
{
  if (vec.size() <= 1 || start < 0 || end >= vec.size())
  {
    return;
  }
  if (start >= end)
  {
    return;
  }
  //把最右侧的拿出来，空出一个位置
  int flag = vec[end];
  int left = start;
  int right = end;

  while (left < right)
  {
    //小于等于全部放左侧,找到大于的来填充右边的空位
    while (left < right && vec[left] <= flag)
    {
      ++left;
    }
    if (left < right)
    {
      vec[right] = vec[left];
      --right;
    }
    //大于的全部放右侧,左侧已经有空位
    while (left < right && vec[right] > flag)
    {
      --right;
    }
    if (left < right)
    {
      vec[left] = vec[right];
      ++left;
    }
  }

  //跳出循环时一定相遇在空位left==right
  assert(left == right);
  vec[left] = flag;

  quik_sort(vec, start, left - 1);
  quik_sort(vec, left + 1, end);
}