#include<iostream>
#include<string>
using namespace std;
string multiple(const string &s,int cal){ //字符串模拟乘法
    string result;
    int carry = 0; // 进位
    for (int i = s.size() - 1; i >= 0; --i){
        int digit=(s[i]-'0')*cal+carry;
        carry = digit / 10; // 更新进位
        result = char(digit % 10 + '0') + result; 
    }
    return carry > 0 ? char(carry + '0') + result : result; // 如果有进位，添加到结果前面
}
int main(){
    string s;
    //长度60位的数字开ll也没用，只能字符串处理输入，但是要乘法就……
    cin>>s;
    //循环数判断逻辑
    int size=s.size();
    //使用模拟乘法来算乘法，然后处理好的字符串*2然后.find，如果找不到就返回No
    for(int i=1;i<=size;i++){
        string cal=multiple(s,i);
        cal+=cal; // 将cal拼接成双倍的字符串
        if(cal.find(s)==string::npos){ // 如果cal中包含s
            cout<<"No"<<endl; // 如果没有找到s，输出No
            return 0; 
        }
    }
    cout<<"Yes"<<endl; // 如果所有i都满足条件，输出Yes
    return 0;

}