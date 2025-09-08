#include<iostream>
#include<vector>
#include<unordered_map> 
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
unordered_map<char,string>mp={
    {'0',"ling"},
    {'1',"yi"},
    {'2',"er"},
    {'3',"san"},
    {'4',"si"},
    {'5',"wu"},
    {'6',"liu"},
    {'7',"qi"},
    {'8',"ba"},
    {'9',"jiu"}
};

string apart(ll num){
    string s=to_string(num);
    string py;
    for(size_t i=0;i<s.size();i++){
        py+=mp[s[i]]+(i==s.size()-1?"":" ");
    }
    return py;
}

ll getValue(string s){
    ll num=0;
    for(char c:s){
        num+=c-'0';
    }
    return num;
}

int main(){
    string s;
    cin>>s;
    cout<<apart(getValue(s));
    return 0;
}

