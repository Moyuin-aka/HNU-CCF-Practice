#include <iostream>
#include <string>
using namespace std;
int calOne(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}// 这个方法是暴力法，计算每个数字的二进制中1的个数，时间复杂度O(log n)，空间复杂度O(1)
//这里也可以用一个位运算，效率更高：
int calOneBit(int n){
    int count=0;
    while(n>0){
        n=(n&(n-1)); // 每次将最低位的1变为0
        count++;
    }
    return count;
}// 这个方法更高效，直接计算二进制中1的个数,完全不用计算其中的0，时间复杂度O(k)，k是二进制中1的个数，空间复杂度O(1)
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s; // ip地址输入带小数点，截取数字得了
        cin >> s;
        int count = 0;
        string num = "";
        for (char c : s)
        {
            if (c == '.')
            { // 如果是小数点
                int digit = stoi(num); 
                //cout<<digit<<endl;// 将数字字符串转换为整数
                count += calOne(digit);
                num = ""; // 重置数字字符串
                continue; // 计算每个数字中1的个数
            }
            num += c; // 将字符添加到数字字符串中
        }
        count += calOne(stoi(num)); // 处理最后一个数字
        cout << count << endl; // 输出结果
    }
    return 0;
}