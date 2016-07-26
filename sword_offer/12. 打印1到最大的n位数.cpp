#include <stdio.h>
#include <string.h>

class Solution
{
public:
    void Print1ToMaxOfNDigits(int n)
    {
        if (n <= 0)
            return;

        char* number = new char[n + 1];
        number[n] = '\0';

        for (int i = 0; i < 10; ++i)
        {
            number[0] = '0' + i;
            Print1ToMaxOfNDigitsRecursively(number, n, 0);
        }
    }

    void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
    {
        if (index == length - 1)
        {
            PrintNumber(number);
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            number[index + 1] = '0' + i;
            Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
        }
    }

    void PrintNumber(char* number)
    {
        bool is_beginnig0 = true;
        int n_length = strlen(number);

        for (int i = 0; i < n_length; ++i)
        {
            if (is_beginnig0 && number[i] != '0')
                is_beginnig0 = false;

            if (!is_beginnig0)
                printf("%c", number[i]);
        }

        printf("\t");
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.Print1ToMaxOfNDigits(2);

    return 0;
}
