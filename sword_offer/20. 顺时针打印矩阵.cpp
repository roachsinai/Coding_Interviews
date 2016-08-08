#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int columes = matrix[0].size();
        int rows = matrix.size();

        vector<int> to_print;

        if (columes <= 0 || rows <= 0)
            return to_print;

        int start = 0;

        while (columes > start*2 && rows > start*2)
        {
            PrintMatrixInCircle(matrix, columes, rows, start, to_print);
            ++start;
        }

        return to_print;
    }

    void PrintMatrixInCircle(const vector<vector<int> >& matrix, int columes, int rows, int start, vector<int>& arr)
    {
        int endY = columes - 1 - start;
        int endX = rows - 1 - start;

        // 从左到右打印一行
        for (int i = start; i <= endY; ++i)
            arr.push_back(matrix[start][i]);

        // 从上到下打印一列
        if (start < endX)
        {
            for (int i=start+1; i <= endX; ++i)
                arr.push_back(matrix[i][endY]);
        }

        // 从右到左打印一列
        if (start < endY && start < endX)
        {
            for (int i = endY-1; i >= start; --i)
                arr.push_back(matrix[endX][i]);
        }

        // 从下到上打印一列
        if (start < endY && start < endX-1)
        {
            for (int i = endX-1; i >= start+1; --i)
                arr.push_back(matrix[i][start]);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int arr1[] = {1,2,3,4};
    int arr2[] = {5,6,7,8};
    int arr3[] = {9,10,11,12};
    int arr4[] = {13,14,15,16};

    vector<int> v1(arr1, arr1+4);
    vector<int> v2(arr2, arr2+4);
    vector<int> v3(arr3, arr3+4);
    vector<int> v4(arr4, arr4+4);

    vector<vector<int> > M;
    M.push_back(v1);
    M.push_back(v2);
    M.push_back(v3);
    M.push_back(v4);

    cout << M.size() << endl;

    s.printMatrix(M);

    return 0;
}
