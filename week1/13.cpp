#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
//很有意思的题！怪异八进制
//0->0
//1->1
//2->2
//4->3
//5->4
//6->5
//7->6
//9->7

//如果这个数字>3,则真实价值-1，如果大于8，则-2，其余和八进制转十进制类似的
ll trans(ll n){
    ll result = 0;
    ll base = 1; // 八进制的基数
    while (n > 0) {
        ll digit = n % 10; // 获取当前位的数字
        if (digit >= 4) {
            digit--; // 如果数字大于等于4，则减1
        }
        if (digit >= 8) {
            digit--; // 如果数字大于等于8，则再减1
        }
        result += digit * base; // 将当前位转换为十进制并累加到结果中
        base *= 8; // 更新基数
        n /= 10; // 去掉当前位
    }
    return result;

}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<trans(n)<<endl;
    }
    return 0;
}