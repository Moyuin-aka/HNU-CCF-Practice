#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //使用set吧，谁出现多次就删掉，最后保留的只有一个名字的，就是缺席的
    int n;
    while(cin>>n&&n!=0){
        unordered_set<string>names;
        for(int i=0;i<2*n-1;i++){
            string name;
            cin>>name;
            auto it = names.find(name);
            if(it != names.end()){
                names.erase(it); //如果找到了，就删掉
            }else{
                names.insert(name); //如果没找到，就插入
            }

        }
        cout<<*names.begin()<<endl; //最后只剩下一个名字，就是缺席的
    }

}