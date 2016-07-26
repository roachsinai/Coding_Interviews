#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if (n < 2)
            return result[n];

        long long fib_1 = 0, fib_2 = 1, fib_n = 0;

        for (unsigned int i = 2; i <= n; ++i)
        {
            fib_n = fib_1 + fib_2;

            fib_1 = fib_2;
            fib_2 = fib_n;
        }

        return fib_n;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
