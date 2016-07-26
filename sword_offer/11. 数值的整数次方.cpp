#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

using namespace std;

class Solution {
public:
    bool g_invalid_input;

    double Power(double base, int exponent) {
        g_invalid_input = false;

        if (equal(base, 0.0) && exponent < 0)
        {
            g_invalid_input = true;
            return 0;
        }

        unsigned int abs_exponent = (unsigned int)exponent;
        if (exponent < 0)
            abs_exponent = (unsigned int) (-exponent);

        double result = PowerWithUnsignedExponent(base, abs_exponent);
        if (exponent < 0)
            result = 1.0 / result;

        return result;
    }

    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;

        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if (exponent & 0x1 ==1)
            result *=base;

        return result;
    }

    bool equal(double num1, double num2)
    {
        if ( abs(num1 - num2) < FLT_EPSILON)
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.Power(2, -2) << endl;
    return 0;
}
