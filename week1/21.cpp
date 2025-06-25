#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// 一个十进制数能否被9（也就是10-1）整除，取决于它所有位数上的数字之和能否被9整除。
//  一个B进制数，它除以 (B-1) 的余数，等于它所有位数上的数字（当成十进制）加起来的和，再除以 (B-1) 的余数。
//  那这个题就很简单了，把每一项加起来，再判断可导致与B-1的mod为0的c的值是多少即可
int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else
    {
        return c - 'a' + 10;
    }
}
char itoc(int n)
{
    if (n >= 0 && n <= 9)
    {
        return n + '0';
    }
    else
    {
        return n - 10 + 'a';
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int B;
        string s;
        cin >> B >> s;
        int sum = 0;
        for (char c : s)
        {
            sum += ctoi(c); // 将每个字符转换为对应的数字并累加
            sum %= (B - 1);
        }
        cout << itoc((B - 1 - sum) % (B - 1)) << endl; // 输出结果，注意要取模
    }
    return 0;
}