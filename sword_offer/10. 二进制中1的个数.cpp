#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;

         while (n)
         {
             ++ count;
             n = n & (n-1);
             cout << n << endl;
         }

         return count;
     }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.NumberOf1(10) << endl;
    return 0;
}
