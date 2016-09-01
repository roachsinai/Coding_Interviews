#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> least_num;

        if (input.size() == 0 || k <= 0 || input.size() < k)
            return least_num;

        priority_queue<int> pq;

        for (int i = 0; i < k; ++i)
            pq.push(input[i]);

        for (int i = k; i < input.size(); ++ i)
        {
            if (input[i] < pq.top())
            {
                pq.pop();
                pq.push(input[i]);
            }
        }

        for (int i = 0; i < k; ++ i)
        {
            least_num.push_back(pq.top());
            pq.pop();
        }

        return least_num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
