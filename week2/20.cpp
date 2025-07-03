#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const long long INF = 1e18;

// Z-algorithm implementation
std::vector<int> z_function(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    int n;
    long long a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;

    std::vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        // 选择1: 编码单个字符 s[i]
        // 从 dp[i] 的状态转移到 dp[i+1]
        dp[i + 1] = std::min(dp[i + 1], dp[i] + a);

        // 选择2: 编码一个子串 s[i..j]
        // 构造 Z-算法需要的字符串
        std::string temp_s = s.substr(i);
        
        // 运行 Z-算法
        std::vector<int> z = z_function(temp_s);
        
        // 找出 s[i...] 的前缀在 s[0...i-1] 中出现的最长长度
        // 注意：这里需要更正一下Z算法的应用逻辑
        // 我们需要找 s[i..] 的前缀是否在 s[0..i-1] 出现
        // 正确的构造应该是 T = s[i...] + # + s[0...i-1]
        int max_len = 0;
        if (i > 0) {
            std::string z_str = s.substr(i) + "#" + s.substr(0, i);
            std::vector<int> z_res = z_function(z_str);
            // 遍历 Z 数组的后半部分
            for(size_t k = s.length() - i + 1; k < z_str.length(); ++k){
                max_len = std::max(max_len, z_res[k]);
            }
        }
        
        // 根据最长可复制长度 max_len 来更新 dp 数组
        // 从 dp[i] 的状态通过复制一个长度为 len 的子串，转移到 dp[i+len]
        for (int len = 1; len <= max_len; ++len) {
            if (i + len <= n) {
                dp[i + len] = std::min(dp[i + len], dp[i] + b);
            }
        }
    }

    std::cout << dp[n] << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}