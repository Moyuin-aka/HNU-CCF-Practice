#include<iostream>
using namespace std;
// 依然是一个简单的
void solve(int n){
    int day=n;
    int percoin=1;
    int count=0;
    while(n>0){
        for(int i=0;i<percoin;i++){
        count+=percoin;
        n--;
        if(n==0) break; // 如果n为0，结束循环
        } 
        percoin++; 
    }
    cout<<day<<" "<<count<<endl;
}
int main(){
    int n;
    while(cin>>n){
        solve(n);
    }
    return 0;
}