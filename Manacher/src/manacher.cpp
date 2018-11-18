#include <vector>
#include <iostream>

//填充特殊字符，这样只需计算奇数回文
std::vector<int> fillSpecWords(const std::vector<int> &srcVec)
{
  if (srcVec.empty())
  {
    return srcVec;
  }
  std::vector<int> ret;
  ret.reserve(srcVec.size() * 2 + 1);

  for (auto &i : srcVec)
  {
    ret.push_back('#');
    ret.push_back(i);
  }
  ret.push_back('#');
  return ret;
}

std::vector<int> manacher(const std::vector<int> &srcVec)
{
  std::vector<int> ret;
  if (srcVec.empty())
  {
    return ret;
  }
  std::vector<int> data = fillSpecWords(srcVec);
  int totalLen = (int)data.size();
  int maxPos = totalLen - 1;
  std::vector<int> widthVec(data.size(), 0); //每个位置的回文长度/2

  int index = 0; //遍历index

  int center = 0;      //回文右边界对应的中心位置
  int centerWidth = 0; //center + centerWidth = 回文右边界

  int longestCenter = 0;
  int longestCenterWidth = 0; //保存最长的回文信息

  for (int index = 0; index < data.size(); ++index)
  {
    bool bNeedCalc = true;

    if (index <= center + centerWidth)
    {
      int left = 2 * center - index; //index位置的对称位置
      int widthTmp = widthVec[left];
      if (index + widthTmp >= center + centerWidth)
      {
        //不在大的回文里，需要重新计算此位置回文长度
        bNeedCalc = true;
        //先赋值为到centerWidth的回文长度，然后看能否向右扩展
        widthVec[index] = center + centerWidth - index;
      }
      else
      {
        bNeedCalc = false;
        widthVec[index] = widthTmp;
      }
    }

    if (bNeedCalc)
    {
      int calcWidth = widthVec[index];
      while (index + calcWidth + 1 <= maxPos && index - calcWidth - 1 >= 0)
      {
        if (data[index + calcWidth + 1] == data[index - calcWidth - 1])
        {
          ++calcWidth;
        }
        else
        {
          break;
        }
      }
      widthVec[index] = calcWidth;

      //record longest
      if (calcWidth > longestCenterWidth)
      {
        longestCenterWidth = calcWidth;
        longestCenter = index;
      }
    }
  }

  for (int i = longestCenter - longestCenterWidth + 1;
       i < longestCenter + longestCenterWidth; i += 2)
  {
    ret.push_back(data[i]);
  }
  return ret;
}