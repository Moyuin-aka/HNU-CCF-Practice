#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 较短的字符串在顶部和底部，而较长的字符串在中间
// 每一对名称都是在该列表的相对的两端，并且在该组中的第一个名字总是在列表的顶部。
// 比如在下面的第一个例子中，Bo和Pat是第一对，Jean和Kevin是第二对,那我们最好的还是两两配对后依次输出？
void output(vector<string> &strs, int n)
{
    cout << "set-" << n << endl;
    for(int i=0;i<strs.size();i+=2){
        cout<<strs[i]<<endl;
    }
    //本质就是先输出0，2，4……然后输出5，3，1……
   for(int i=(strs.size()%2==0?strs.size()-1:strs.size()-2);i>0;i-=2){
        cout<<strs[i]<<endl;
    }

}
int main()
{
    int n;
    int count = 1;
    while (cin>>n&&n!=0)
    {
        vector<string> strs;
        string name;
        while (n--)
        {
            cin >> name;
            strs.push_back(name);
        }
        output(strs, count);
        count++;
    }
    return 0;
}