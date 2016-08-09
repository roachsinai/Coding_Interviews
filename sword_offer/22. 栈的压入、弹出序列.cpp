#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(const vector<int>& pushV, const vector<int>& popV) {
        bool b_possible = false;

        if (pushV.size() != 0 && pushV.size() == popV.size())
        {
            stack<int> s_data;
            size_t i, j = 0;

            for (i = 0; i < popV.size(); ++i)
            {
                while (s_data.empty() || popV[i] != s_data.top())
                {
                    if (j == pushV.size())
                        break;

                    s_data.push(pushV[j++]);
                }

                if (s_data.top() != popV[i])
                    break;

                s_data.pop();
            }

            if (s_data.empty() && i == popV.size())
                b_possible  = true;
        }

        return b_possible;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
