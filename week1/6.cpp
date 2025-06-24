#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//暴力比较，lambda表达式排序，然后建立结构体写即可
// 计算单个字符串的逆序对数量
int calculateInversions(const string &s)
{
    int inversions = 0;
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (s[i] > s[j])
            {
                inversions++;
            }
        }
    }
    return inversions;
}
struct DNA
{
    string sequence; // 原始序列
    int inversions;  // 对应的逆序对数量
    int index;       // 原始索引位置
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length, n;
    // 虽然题目里length没用到，但好习惯是读进来
    cin >> length >> n;
    vector<DNA> dnaList(n);
    vector<DNA> dna_list(n);
    for (int i = 0; i < n; ++i)
    {
        dna_list[i].index = i;
        cin >> dna_list[i].sequence;
        dna_list[i].inversions = calculateInversions(dna_list[i].sequence);
    }
    // 按逆序对数量排序
    sort(dna_list.begin(), dna_list.end(), [](const DNA &a, const DNA &b)
         { return a.inversions < b.inversions || (a.inversions == b.inversions && a.index < b.index); });
    for (int i = 0; i < n; ++i)
    {
        cout << dna_list[i].sequence << endl;
    }

    return 0;
}