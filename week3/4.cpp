#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
typedef long long ll;
using namespace std;
// 对于一辆公交车和n个车站，a1,a2,...,an为该公交车在各站的记录数据。
// 其中ai表示该公交车在第i个车站的上车人数
// 假定w为该公交车可容纳的最大乘客人数，编程求出在第一站停靠之前公交车上人数的可能数据有多少种？
signed main(){
    ll n,w;
    cin>>n>>w;
    // n为车站数，w为公交车可容纳的最大乘客人数
    vector<ll> a(n+1,0);
    ll minS = 0, maxS = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i] += a[i-1]; // 前缀和
        minS = min(minS, a[i]); // 最小值
        maxS = max(maxS, a[i]); // 最大值
    }
    cout<<max(0LL, min(w, w - maxS) - max(0LL, -minS) + 1) << endl;
    return 0;
//  用模拟法会忽略下界，这道题可以直接用数学方法取交集解决
// L = max(0, -minS)
// R = min(w, w - maxS)
// 答案 = max(0, R - L + 1)
}
    //vector<ll> dp(n+1, 0);
    // 考虑上车人不能是负数，最低为0？
    /*for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=max(dp[i-1] + a[i],0LL);
    }
    // 那就是总和上下车，看看初始人数的可能性,一样做线性时间表？载人最多的时候不能超过w，也就是做dp找载人最多的时候然后W减去它,0人也算
    ll ans = *max_element(dp.begin(), dp.end());
    cout<< max(0LL, w - ans+1)  << endl;
}*/
//n=2, w=5
//a = [-3, +2]
//	•	你的写法：
//dp[1] = max(0-3,0)=0, dp[2]=max(0+2,0)=2 → ans=2
//输出 = 5 - 2 + 1 = 4，认为有 4 种初始人数。
//	•	真情况：
//S = [-3, -1]
//minS=-3 → L = max(0,3)=3
//maxS=-1 → R = min(5,6)=5
//答案 = 5-3+1=3
//只能有 3 种初始人数。