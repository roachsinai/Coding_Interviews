#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string result;
        if (numbers.size() == 0)
            return result;

        vector<string> v_str;

        for (unsigned int i = 0; i < numbers.size(); ++ i)
        {
            stringstream ss;
            ss << numbers[i];
            v_str.push_back(ss.str());
        }

        sort(v_str.begin(), v_str.end(), comp);

        for (unsigned int i = 0; i < v_str.size(); ++ i)
            result.append(v_str[i]);

        return result;
    }

    static int comp(const string& s1, const string& s2)
    {
        string str1 = s1 + s2;
        string str2 = s2 + s1;
        return str1 < str2;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    int arr[] = {3, 32, 321};
    vector<int> v_arr(arr, arr+3);

    cout << s.PrintMinNumber(v_arr) << endl;

    return 0;
}
