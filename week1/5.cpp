#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
// 暴力法，直接遍历每个数，判断是否满足条件
// 注意！n是一个数，m是范围的上限
int main(){
    ll n,m;
    cin>>m>>n;
    string ns=to_string(n);
    vector<ll>a;
    for(ll i=n;i<=m;i++){
        string s=to_string(i);
        bool mutiple=(i%n==0);
        bool contain=(s.find(ns)!=string::npos); 
        if(mutiple||contain){
            a.push_back(i);
        }
    } 
    for(int i=0;i<a.size();i++){
        cout<<a[i];
        if(i!=a.size()-1) cout<<" ";
    }
}