#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    stack<int> s_data, s_min;

    void push(int value) {
        s_data.push(value);

        if (s_min.size() == 0 || value < s_min.top())
            s_min.push(value);
        else
            s_min.push(s_min.top());
    }

    void pop() {
        if (!s_data.empty())
        {
            s_data.pop();
            s_min.pop();
        }
    }

    int top() {
        if (s_data.empty())
            return 0;
        return s_data.top();
    }

    int min() {
        if (s_min.empty())
            return 0;
        return s_min.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
