#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
unordered_map<string, int> days = {
    {"monday", 1},
    {"tuesday", 2},
    {"wednesday", 3},
    {"thursday", 4},
    {"friday", 5},
    {"saturday", 6},
    {"sunday", 7}};
// 满足公式就好了，在 [L, R] 这个区间里，找一找有多少个整数 d 满足 (d - 1) % 7 == diff
// 比赛的总天数（包括第一和最后一天）不少于L天，也不多于R天
void solve(const string &begin, const string &end, int a, int b)
{
    int start = days[begin];
    int endd = days[end];
    int diff = (endd - start + 7) % 7; // 计算两天之间的差值，注意循环
    int found_count = 0;
    int solution = 0;

    // 因为 L, R <= 100，a直接遍历所有可能的天数
    for (int d = a; d <= b; ++d)
    {
        if ((d - 1) % 7 == diff)
        {
            found_count++;
            solution = d;
        }
    }

    if (found_count == 0)
    {
        cout << "impossible" << endl;
    }
    else if (found_count == 1)
    {
        cout << solution << endl;
    }
    else
    {
        cout << "many" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string begin, end;
        int a, b;
        cin >> begin >> end >> a >> b;
        solve(begin, end, a, b);
    }
    return 0;
}