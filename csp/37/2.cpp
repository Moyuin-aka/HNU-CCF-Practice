#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> value(m + 1, 0); // A0 = 0，不喂苹果的时候没收益
    for (int i = 1; i <= m; ++i) cin >> value[i];
    // 如何计算呢……
    vector<long long> dp(n + 1, 0); // dp[j] = 用 j 个苹果的最大快乐
    // 完全背包：外层枚举每天投喂 i(1..m)，内层容量 j 递增
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] = max(dp[j], dp[j - i] + value[i]);
        }
    }
    cout << dp[n] ;
    return 0;
    
}