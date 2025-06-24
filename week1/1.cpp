#include <iostream>
#include <vector>
#include <algorithm>
// 排序统计？记录每一个数的数量，使用桶排序思想，然后看数值最大的第一个索引
using namespace std;
int main()
{
    int n = -1;
    while (n != 0)
    {
        cin >> n;
        if (n == 0)
            break;
        vector<int> num(10001, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            num[x]++;
        }
        int maxCount=0;
        int maxIndex=0;
        for (int i = 0; i <= 10000; i++){
            if(num[i]>maxCount){
                maxCount = num[i];
                maxIndex = i;
            }
        }
        cout<<maxIndex<<endl; // 输出出现次数最多的数字
    }
    return 0;
}
