#include <iostream>
using namespace std;

int main()
{
    char a[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int *p = (int*)a;

    cout << *p << ' ' << *p+1 << ' ' << *(p+3) << endl;

    return 0;
}
