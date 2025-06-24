#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll cal(vector<ll> &a)
{
    // 平均方差向下取整，直接int得了,这里有一个误区，不能直接算int，有偏差，得用double算完直接floor？
    ll sum = 0;
    double sum_square = 0;
    for (ll num : a)
    {
        sum += num;
    }
    double mean = static_cast<double>(sum) / a.size(); // 平均值,注意转化成double强制运算，不然c++特性总是差一点
    for (ll num : a)
    {
        sum_square += (num - mean) * (num - mean); // 计算平方
    }
    double variance = sum_square / a.size(); // 计算方差
    return floor(variance); // 平均方差向下取整
}
//还有个更加简洁的写法，一次遍历
ll cal_one_pass(vector<ll> &a) {
    ll sum_of_nums = 0;
    ll sum_of_squares = 0;
    int n = a.size();

    // 一次遍历，计算和与平方和
    for (ll num : a) {
        sum_of_nums += num;
        sum_of_squares += num * num;
    }

    // 使用double进行计算以保证精度
    double mean = static_cast<double>(sum_of_nums) / n;
    double mean_of_squares = static_cast<double>(sum_of_squares) / n;

    // 根据公式计算方差
    double variance = mean_of_squares - mean * mean;

    return floor(variance);
}
int main()
{
    int n = -1;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break; // 输入0时结束
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; // 输入每个数
        }
        ll result = cal(a);     // 计算平均方差
        cout << result << endl; // 输出结果
    }
    return 0;
}