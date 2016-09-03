/*
随机抽取扑克牌中的5张牌，判断是不是顺子，即这5张牌是不是连续的。其中A看成1，J看成11，Q看成12，K看成13，大小王可以看成任何需要的数字。把0看成大小王。

思路1:

在没有重复牌的情况下：
1. 如果5张牌是顺子，那么牌中的最大值减最小值（差值，不包括0）不能超过4；
2. 差值=4，那么可以有任意一张0（不过，最多有2张了^_^）12345->12005/10305，还是对的
3. 如果差值=3，最少一个0，2345->2305/2045，还是对的
4. 差值为2，则最少两个0，野肯定是对的
5. 差值为1，输入不合法

前提：没有重复牌（肯定不是顺子），return false

实现：
1. 排序，O(nlogn)
2. 空间复杂度 O(n) 时间复杂度 O(n)

思路2:
看0的个数和排序之后的数组相邻数字之间的空缺总数是否相等
*/

#include <iostream>
#include <vector>

using namespace std;

#define N 14
bool isStraight(vector<int> &data)
{
    if (data.size() != 5)
        return false;
        
    int* tmp = new int[N];
    
    for (int i = 0; i < N; ++ i)
        tmp[i] = 0;
        
    int max = 1;
    int min = 13;
        
    for (int i = 0; i < data.size(); ++ i)
    {
        if (data[i] != 0)
        {
            ++ tmp[data[i]];
            if (tmp[data[i]] >= 2)
                return false;
                
            if (data[i] > max)
                max = data[i];
            if (data[i] < min)
                min = data[i];
        }
    }
    
    delete[] tmp;
    return (max - min <= 4);
}

int main()
{
    return 0;
}
