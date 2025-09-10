#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
long double fx(ll x,ll b,ll c){
    return x*x+b*x+c;
}
bool isodd(ll x){
    return x%2==0;
}
int main(){
    ll b,c,l,r;
    //做积分
    cin>>b>>c>>l>>r;
    ll ans=0;
    for(ll i=l;i<=r;i+=2){
        if(isodd(i)){
            ans+=fx(i,b,c);
        }
        else{
            i+=1;
            if(i>r) break;
            ans+=fx(i,b,c);
        }
        //cout<<ans<<endl;
    }
    cout<<ans*2;
    return 0;

}