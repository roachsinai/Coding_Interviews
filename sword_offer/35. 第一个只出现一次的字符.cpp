#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.size() == 0)
            return -1;

        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        unsigned int i;
        for (i = 0; i < tableSize; ++ i)
            hashTable[i] = 0;

        for (i = 0; i < str.size(); ++ i)
            hashTable[str[i]] ++;

        for (i = 0; i < str.size(); ++ i)
            if (hashTable[str[i]] == 1)
                return i;

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
