#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//注意题目是字符串输入！！！！！！
//修了快一个小时的bug了，结果发现是输入有问题！！！😭
// 给一个二维矩阵，看列是否是满的？对于每一行，如果每个列项存在大于1的数值且列判断是否有可忽略开关，则输出YES，否则输出NO
bool ignored(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> colValues(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                colValues[j]++; // 标记该列有大于1的数值
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (colValues[j] == 0)
        {
            return false; // 直接判定为NO
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool lineignored = true;
        for (int j = 0; j < m; j++)
        {

            if (matrix[i][j] == 1 && colValues[j] == 1)
            {
                lineignored = false; // 不可忽略一个灯只有一个开关的开关
                break;               // 如果有一个开关是可以忽略的，则不满足条件?
            }
        }
        if (lineignored)
        {
            return true; // 如果有一行的开关都可以忽略，则不满足条件
        }
    }

    return false; // 其实这里return啥没意义了
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        for (int j = 0; j < m; j++)
        {
            matrix[i][j]=s[j]-'0'; // 输入矩阵
        }
    }
    if (ignored(matrix, n, m))
    {
        cout << "YES" << endl; // 如果满足条件，输出YES
    }
    else
    {
        cout << "NO" << endl; // 否则输出NO
    }
    return 0;
}