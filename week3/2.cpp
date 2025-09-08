#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string num;
    cin>>num;
    vector<int>ans(10,0);
    for(char c:num){
        ans[c-'0']++;
    }
    for(int i=0;i<10;i++){
        if(ans[i])cout<<i<<":"<<ans[i]<<endl;
    }
    return 0;
    
}