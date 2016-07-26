#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() <= 0)
            throw "Invalid parameters.";

        int length = rotateArray.size();
        int p1 = 0;
        int p2 = length-1;
        int p_mid = p1;

        while (rotateArray[p1] >= rotateArray[p2])
        {
            if (p2 - p1 == 1)
            {
                p_mid = p2;
                break;
            }
            p_mid = (p1 +p2) / 2;
            if (rotateArray[p1] == rotateArray[p_mid] && rotateArray[p_mid] == rotateArray[p2])
                return minInOrder(rotateArray);

            if (rotateArray[p1] <= rotateArray[p_mid])
                p1 = p_mid;
            else if (rotateArray[p2] >= rotateArray[p_mid])
                p2 = p_mid;

        return rotateArray[p_mid];
    }

    int minInOrder(vector<int> &data)
    {
        int i = 1;
        int min_rotate = data[0];
        for (; i < data.size(); ++i)
            if (data[i] < min_rotate)
                min_rotate = data[i];

        return min_rotate;
    }
};

int main(int argc, char const *argv[])
{
    int arr[5] =  {3,4,5,1,2};
    vector<int> v(arr, arr+4);
    Solution s;
    cout << s.minNumberInRotateArray(v) << endl;
    return 0;
}
