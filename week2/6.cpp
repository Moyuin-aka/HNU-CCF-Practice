#include<iostream>
#include<string>
using namespace std;
//26进制加法，去年期末是不是写过……
//这个还比26进制加法更直观一些？每个数会用小A所设计的操作系统中的表示方法来表示，如：bsadfasdf。即每个数的各个位均由26个小写字母a-z中的一个来表示。
void solve(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    int maxLen = max(len1, len2);
    string result(maxLen, 'a'); // 初始化结果字符串

    int carry = 0; // 进位
    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < len1) ? (s1[len1 - 1 - i] - 'a') : 0;
        int digit2 = (i < len2) ? (s2[len2 - 1 - i] - 'a') : 0;

        int sum = digit1 + digit2 + carry;
        result[maxLen - 1 - i] = 'a' + (sum % 26); // 当前位的字符
        carry = sum / 26; // 更新进位
    }

    if (carry > 0) {
        result.insert(result.begin(), 'a' + carry - 1); // 如果有进位，插入到最前面
    }

    cout << result << endl;
}
int main() {
    int n;
    cin >> n;
    string s1, s2;
    while (n--) {
        cin >> s1 >> s2;
        solve(s1, s2);
    }
    return 0;
}