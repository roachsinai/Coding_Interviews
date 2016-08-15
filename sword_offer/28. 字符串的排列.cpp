#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> s_permuts;
        if (str.size() == 0)
            return s_permuts;

        Permutation(s_permuts, str, 0);

        sort(s_permuts.begin(), s_permuts.end());

        return s_permuts;
    }

    void Permutation(vector<string>& s_permuts, string &str, int begin)
    {

        if (begin == str.size()-1)
        {
            s_permuts.push_back(str);
        }

        else
        {
            for (int to_exchange = begin; to_exchange < str.size(); ++ to_exchange)
            {
                if (begin == to_exchange || str[to_exchange] != str[begin])
                {
                    char temp = str[to_exchange];
                    str[to_exchange] = str[begin];
                    str[begin] = temp;

                    Permutation(s_permuts, str, begin + 1);

                    temp = str[to_exchange];
                    str[to_exchange] = str[begin];
                    str[begin] = temp;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    string test_s("abc");

    vector<string> s_vec = s.Permutation(test_s);

    for (int i = 0; i < s_vec.size(); ++i)
        cout << s_vec[i] << endl;

    return 0;
}
