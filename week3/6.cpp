#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map> 
#include<vector>
typedef long long ll;
using namespace std;
unordered_map<char,string>mp={
    {'0',"(Zero)"},
    {'1',"(One)"},
    {'2',"(Two)"},
    {'3',"(Three)"},
    {'4',"(Four)"},
    {'5',"(Five)"},
    {'6',"(Six)"},
    {'7',"(Seven)"},
    {'8',"(Eight)"},
    {'9',"(Nine)"}
    
};

vector<ll>getCount(string s){
    vector<ll>count(10,0);
    for(char c:s){
        if(mp.count(c))
        count[c-'0']++;
    }
    return count;
}

string toWords(string s){
    string res;
    for(size_t i=0;i<s.size();i++){
        if(mp.count(s[i])) res+=mp[s[i]];
        else res+=s[i];
    }
    return res;
}

int main(){
    string s;
    getline(cin,s);
    vector<ll>count=getCount(s);

    cout<<toWords(s)<<endl;
    for(int i=0;i<10;i++){
         cout<<count[i]<<" ";
    }
    return 0;
}