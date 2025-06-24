#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 注意！有空格！！！！用char栈不好处理空格，每个单词之间有空格，注意一下
int main()
{
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符，准备读取下一行
    //注意不能放循环里
    while (n--)
    {
        string s;        // 输入每一行的字符串，得用getcin
        getline(cin, s); // 读取整行字符串，包括空格
        stack<char> st;
        string result = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            { // 如果是空格，直接开始处理
                while (!st.empty())
                {
                    result += st.top(); // 逐个弹出栈顶字符并添加到
                    st.pop();           // 弹出栈顶字符
                }
                result += ' '; // 添加空格到结果中
                continue;      // 跳过空格，继续处理下一个字符
            }
            st.push(s[i]); // 将每个字符压入栈中
        }
        // 处理最后一个单词（没有空格结尾的情况）
        while (!st.empty())
        {
            result += st.top(); // 逐个弹出栈顶字符并添加到
            st.pop();           // 弹出栈顶字符
        }
        cout << result << endl; // 输出结果
    }
    return 0;
}