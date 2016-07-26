#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        int result[2] = {1, 2};
        if (number < 2)
            return result[number];

        long long step1 = 1, step2 = 2, step;
        for (int i = 2; i <= number; ++i)
        {
            step = step1 + step2;
            step1 = step2;
            step2 = step;
        }

        return step;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
