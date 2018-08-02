// 两个数的最小公倍数(Lowest Common Multiple) = 两个数的乘积 / 两个数的最大公约数

// 在数论中，如果两个或两个以上的整数的最大公约数是 1，则称它们为互质
// 最大公约数（英语：Greatest Common Divisor，简写为G.C.D.；或Highest Common Factor，简写为H.C.F.）


// 1不是质数

// 求最大公约数：欧几里得法（辗转相除法）
// 求a和b的最大公约数m
// 我们知道 a = kb + r，可以表示任意两个整数之间的关系，且 a%m == b%m == 0，所以 r%m == 0
// 也就是说 m 也是 b 和 r 的最大公约数

#include <iostream>
using namespace std;

int Gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        Gcd(y, x%y);
}



int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;

    int gcd = Gcd(a, b);
    int lcm = a * b / gcd;

    cout << "gcd: " << gcd << endl;
    cout << "lcm: " << lcm << endl;
    
    return 0;
}
