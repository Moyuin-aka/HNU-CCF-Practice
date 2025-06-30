#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//是不是就是取中间数啊，奇数个数就取中间数，直接找max+min/2的距离最小的值，算法从O(n^2)降到O(nlogn)
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i]; // 输入每个数
    }
    sort(a.begin(), a.end()); // 排序
    int mid=(a[0]+a[n-1])/2;
    int num=INT_MAX;
    for(int i=0;i<n;i++){
        if(abs(num-mid)>abs(a[i]-mid)){
            num=a[i]; // 找到距离中间数最近的数
        }
    }
    cout<<num<<endl; // 输出结果
    return 0;

}