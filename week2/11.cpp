#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    cin>>n>>k;
    set<ll>s;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        s.insert(x);
    }
    ll count=0;
    for(auto it=s.begin();it!=s.end()&&count<k;it++){
        count++;
        cout<<*it<<" ";
    }
    return 0;
}