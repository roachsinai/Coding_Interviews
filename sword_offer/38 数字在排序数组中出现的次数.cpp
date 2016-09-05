#include <iostream>
#include <vector>

using namespace std;

// 要求在 O(logn) 时间复杂度
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;

        if (data.size() != 0)
        {
            int firstK = GetFirstK(data, k, 0, data.size()-1);
            int lastK = GetLastK(data, k, firstK, data.size()-1);

            if (lastK > -1 && firstK > -1)
                count = (lastK - firstK + 1);
        }

        return count;
    }

    int GetFirstK(vector<int>& data,int k, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = (end + start) / 2;

        if (data[mid] == k)
        {
            if (mid == 0 || data[mid-1] != k)
                return mid;
            else
                end = mid - 1;
        }
        else if (data[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;

        return GetFirstK(data, k, start, end);
    }

    int GetLastK(vector<int>& data,int k, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = (end + start) / 2;
        if (data[mid] == k)
        {
            if (mid == data.size()-1 || data[mid+1] != k)
                return mid;
            else
                start = mid + 1;
        }
        else if (data[mid] < k)
            start = mid + 1;
        else
            end = mid - 1;

        return GetLastK(data, k, start, end);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};

    vector<int> v_data(data, data+8);

    cout << s.GetNumberOfK(v_data, 3) << endl;
    return 0;
}
