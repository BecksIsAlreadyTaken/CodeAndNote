#include <iostream>
using namespace std;
int main()
{
    int p, e, i, d;
    int n = 0;
    while (cin >> p >> e >> i >> d && (p != -1))
    {
        // 中国剩余定理
        int k = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
        if (k == 0)
            k = 21252;
        cout << "Case " << ++n << ": the next triple peak occurs in " << k << " days." << endl;
    }
    return 0;
}