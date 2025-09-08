#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 比较两个数的大小，a >= b 返回 true
bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    return a >= b;
}

// 大数减法：a - b，假设 a >= b
string subtract(string a, string b) {
    // 补齐长度
    while (b.length() < a.length()) {
        b = "0" + b;
    }
    
    string result = "";
    int borrow = 0;
    
    for (int i = a.length() - 1; i >= 0; i--) {
        int digit_a = a[i] - '0';
        int digit_b = b[i] - '0';
        
        int diff = digit_a - digit_b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result = char(diff + '0') + result;
    }
    
    // 去除前导零
    size_t start = result.find_first_not_of('0');
    if (start == string::npos) {
        return "0";
    }
    return result.substr(start);
}

// 大数除法
pair<string, string> divide(string dividend, string divisor) {
    if (divisor == "0") {
        throw invalid_argument("除数不能为0");
    }
    
    string quotient = "0";
    string remainder = dividend;
    
    if (!compare(dividend, divisor)) {
        return {quotient, remainder};
    }
    
    // 试商法
    string current = "";
    quotient = "";
    
    for (char digit : dividend) {
        current += digit;
        
        // 去除前导零
        size_t start = current.find_first_not_of('0');
        if (start != string::npos) {
            current = current.substr(start);
        } else {
            current = "0";
        }
        
        int count = 0;
        while (compare(current, divisor)) {
            current = subtract(current, divisor);
            count++;
        }
        
        quotient += char(count + '0');
    }
    
    // 去除商的前导零
    size_t start = quotient.find_first_not_of('0');
    if (start != string::npos) {
        quotient = quotient.substr(start);
    } else {
        quotient = "0";
    }
    
    return {quotient, current};
}

int main() {
    string line;
    getline(cin, line);
    
    size_t space_pos = line.find(' ');
    string A = line.substr(0, space_pos);
    string B = line.substr(space_pos + 1);
    
    try {
        auto result = divide(A, B);
        cout << result.first << " " << result.second << endl;
    } catch (const exception& e) {
    }
    
    return 0;
}