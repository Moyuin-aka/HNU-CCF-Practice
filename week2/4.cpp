#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
// 把约数存储计算是需要的
vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i && n/i!=1) { // 避免重复添加平方根和自身，形成真约数
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}
void friendly(int n, int m) {
    vector<int> divisors_n = getDivisors(n);
    vector<int> divisors_m = getDivisors(m);
    
    int sum_n = 0, sum_m = 0;
    for (int d : divisors_n) {
        if (d != n) sum_n += d; // 真约数
    }
    for (int d : divisors_m) {
        if (d != m) sum_m += d; // 真约数
    }
    
    if (sum_n == m && sum_m == n) {
        cout << "YES" << endl; // 互为友好数
    } else {
        cout << "NO" << endl; // 不是互为友好数
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        friendly(n, m);
    }
    return 0;
}