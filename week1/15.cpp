#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct team
{
    string name;
    int score;
    int ball;
};
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        // 处理输入就能解决的事情，不过有点问题……
        // 不会一次性给出所有队伍，我要怎么找分数最高的两个队伍？sort的lambda可以做处理
        // 输入说了，只有12行，那就用 unordered_map 得了
        unordered_map<string, team> stats;
        for (int i = 0; i < 12; i++)
        { 
            string name1, vs, name2;
            int score1, score2;
            cin >> name1 >> score1 >> vs >> score2 >> name2;
            stats[name1].name = name1;
            stats[name2].name = name2;

            stats[name1].score += (score1 > score2) ? 3 : (score1 < score2) ? 0
                                                                            : 1; // 胜3分，负0分，平1分
            stats[name2].score += (score2 > score1) ? 3 : (score2 < score1) ? 0
                                                                            : 1;
            stats[name1].ball += score1 - score2;
            stats[name2].ball += score2 - score1;
        }
        // 现在统计完了，开始排序
        vector<team> teams;
        for (const auto &[name, stat] : stats)
        {
            teams.push_back(stat);
        }
        sort(teams.begin(), teams.end(), [](const team &a, const team &b)
             {
            if (a.score == b.score)
                return a.ball > b.ball;
            return a.score > b.score; });
        cout << teams[0].name << " " << teams[1].name << endl;
    }
    return 0;
}