#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char,char>match={
    {'(',')'},
    {'[',']'},
    {'{','}'},
    {'<','>'}
};
// 直接用栈来处理括号匹配问题，注意括号的匹配规则
bool isValid(const string &s){
    stack<char> st; // 用栈来存储左括号
    for (char c : s) {
        if (match.count(c)) { // 如果是左括号
            st.push(c); // 压入栈中
        } else { // 如果是右括号
            if (st.empty() || match[st.top()] != c) { // 栈为空或不匹配
                return false; // 不合法
            }
            st.pop(); // 匹配成功，弹出栈顶元素
        }
    }
    return st.empty(); // 如果栈为空，则所有括号都匹配成功
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<(isValid(s)?"Yes":"No")<<endl; // 输出结果
    }
    return 0;
}
