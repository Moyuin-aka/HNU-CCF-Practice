#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
// 这不是和15题一个套路吗，就排序改一下
struct team
{
    string name;
    int score;
    int ball;
    int getball;
};
int main()
{
    int n;
    cin >> n;
    unordered_map<string, team> stats;
    // 这个题还是坑在输入
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        stats[name].name = name;
    }
    cin.ignore(); // 忽略换行符，准备读取下一行
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        string line;
        getline(cin, line);
        size_t pos1 = line.find('-');
        size_t pos2 = line.find(' ');
        size_t pos3 = line.find(':');
        string name1 = line.substr(0, pos1);
        string name2 = line.substr(pos1 + 1, pos2 - pos1 - 1);
        int score1 = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        int score2 = stoi(line.substr(pos3 + 1));
        stats[name1].score += (score1 > score2) ? 3 : (score1 < score2) ? 0
                                                                        : 1;
        stats[name2].score += (score2 > score1) ? 3 : (score2 < score1) ? 0
                                                                        : 1;
        stats[name1].ball += score1 - score2; // 记录净进球
        stats[name2].ball += score2 - score1;
        stats[name1].getball += score1; // 记录进球数
        stats[name2].getball += score2;
    }
    vector<team> teams;
    for (const auto &[name, stat] : stats)
    {
        teams.push_back(stat);
    }
    sort(teams.begin(), teams.end(), [](const team &a, const team &b)
         {
        if (a.score != b.score) return a.score > b.score; // 按分数降序
        if (a.ball != b.ball) return a.ball > b.ball; // 按
        if( a.getball != b.getball) return a.getball > b.getball; // 按进球数降序
        return a.name < b.name; // 按字典序升序
        });
    // 表示进入淘汰赛阶段的球队，按照字典序进行排列,这点好阴间啊，又要开一个sort
    sort(teams.begin(), teams.begin() + n / 2, [](const team &a, const team &b)
         { return a.name < b.name; });
    for (int i = 0; i < n / 2; i++)
    {
        cout << teams[i].name << endl;
    }
    return 0;
}
