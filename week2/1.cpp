#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
// 反转后栈弹出？
int main()
{
        string str;
        while(getline(cin, str)){
        reverse(str.begin(), str.end()); // 反转字符串
        stack<char> st;
        for (char c : str)
        {
            if (c == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top(); // 输出栈顶元素
                    st.pop();         // 弹出栈顶元素
                }
                cout << " "; // 输出空格
            }
            else
            {
                st.push(c); // 将字符压入栈中
            }
        }
        while (!st.empty())
        {
            cout << st.top(); // 输出栈顶元素
            st.pop();         // 弹出栈顶元素
        }
        cout << endl;
    }

return 0;
}