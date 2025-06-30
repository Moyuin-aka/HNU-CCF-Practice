#include<iostream>
using namespace std;
//非常朴实的递归
//一个正整数n，如果是偶数，就把n砍掉一半；如果是奇数，把n变成 3*n+ 1后砍掉一半，直到该数变为1为止
int collatz(int n,int count){
    if(n==1) return count;
    if(n%2==0) return collatz(n/2,count+1);
    return collatz((3*n+1)/2,count+1);
}
int main(){
    int n;
    while(cin>>n){
        if(n==0) break; // 输入0时结束
        cout<<collatz(n,0)<<endl; 
    }
    return 0;
}