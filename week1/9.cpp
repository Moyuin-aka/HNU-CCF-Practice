#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TimePeriod
{
    int start, end, continuous; // 工作时间段的开始和结束时间，以及连续工作时间
};
int main()
{
    int n;          // 工作时间段数
    int p1, p2, p3; // 三个时间段的效率
    int t1, t2;     // 两个时间段的工作时间节点
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    // 找[l1, rn]的总耗电量
    long long totalPower = 0; // 总耗电量
    vector<TimePeriod> periods(n);
    for (int i = 0; i < n; i++)
    {
        cin >> periods[i].start >> periods[i].end;
        periods[i].continuous = periods[i].end - periods[i].start; // 计算连续工作时间
        totalPower += periods[i].continuous * p1; // 初始总耗电量
    }
    //主要是间隔时间段里比较值得注意……
    for (int i = 0; i < n - 1; i++)
    {
        // 检查相邻时间段之间的间隔
        if (periods[i].end < periods[i + 1].start)
        {
            int gap = periods[i + 1].start - periods[i].end; // 间隔时间
            totalPower+=(gap>t1?p1*t1:p1*gap)+(gap>t2+t1?(p2*t2+p3*(gap-t2-t1)):(gap>t1?p2*(gap-t1):0)); // 间隔时间段的耗电量
        }
    }
    cout<<totalPower<<endl; // 输出总耗电量
    return 0;

}