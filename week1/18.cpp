#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 只有前10名车手按以下顺序获得分数：25、18、15、12、10、8、6、4、2、1
// 如果有平分，则冠军是赢的最多的人（即排位第一）。如果还是平分，则选择得到排位第二最多的人
// 两个得分系统来分别确定冠军
// 后来又提出了另一个得分制度，其中冠军是赢的最多的。如果有平手，冠军是得分最多的。如果仍然存在平手，则按原来的得分制度进行，即比较第二、第三、第四、...排位的次数。
struct Driver
{
    string name;
    int points; // 总分数
    vector<int> rank_counts = vector<int>(51, 0);// 第一个元素表示第一名的次数，即胜利次数
};
// 这个题巨坑啊，得用vector存储车手得了几次第一第二
int main()
{
    int T;
    cin >> T;
    unordered_map<string, Driver> drivers;
    int points[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1}; // 前10名车手的得分
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            drivers[name].name = name;
            drivers[name].rank_counts[i + 1] += 1; // 得到一次排位
            if (i < 10)
                drivers[name].points += points[i];
        }
    }
    // 两套排位制度，先写第一个
    vector<Driver> driverList;
    for (const auto &[name, driver] : drivers)
    {
        driverList.push_back(driver);
    }
    sort(driverList.begin(), driverList.end(), [](const Driver &a, const Driver &b)
         {
        if (a.points != b.points) return a.points > b.points; // 按总分数降序
        if(a.rank_counts[1] != b.rank_counts[1]) return a.rank_counts[1] > b.rank_counts[1]; // 按胜利次数降序
        for (int i = 1; i <= 50; ++i) {
        if (a.rank_counts[i] != b.rank_counts[i]) {
            return a.rank_counts[i] > b.rank_counts[i];
        }
    }
    return a.name < b.name; });
    cout << driverList[0].name << endl;
    // 现在开始第二个得分制度
    sort(driverList.begin(), driverList.end(), [](const Driver &a, const Driver &b)
         {
             if (a.rank_counts[1] != b.rank_counts[1])
                 return a.rank_counts[1] > b.rank_counts[1]; // 按胜利次数降序
             if (a.points != b.points)
                 return a.points > b.points; // 按总分数降序
             for (int i = 1; i <= 50; ++i)
             {
                 if (a.rank_counts[i] != b.rank_counts[i])
                 {
                     return a.rank_counts[i] > b.rank_counts[i];
                 }
             } // 如果所有排位都相同，则按字典序升序
             return a.name < b.name; });
    cout << driverList[0].name << endl;
    return 0;
}
