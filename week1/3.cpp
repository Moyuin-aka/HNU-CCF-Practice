#include <iostream>
#include <vector>
using namespace std;
#define int long long
struct pos
{
    int x, y; // 结构体好输入
};

// 比第2题简单的多，统计一下x为小于0和大于0的个数，如果为1或0就过
bool check(vector<pos> &a, int n)
{
    int count1 = 0, count_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].x > 0)
            count1++;
        else if (a[i].x < 0)
            count_1++;
    }
    return count1 == 1 || count_1 == 1||count1 == 0 || count_1 == 0; // 如果有一个位置的状态为1或-1，或者所有位置的状态都为0，则满足条件
}
signed main()
{
    int n;
    cin >> n;
    vector<pos> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y; // 输入位置和状态
    }
    if (check(a, n))
        cout << "Yes" << endl; // 如果满足条件，输出Yes
    else
        cout << "No" << endl; // 否则输出No
    return 0;
}