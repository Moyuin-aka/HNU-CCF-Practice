#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cstdio> // for FILE operations
using namespace std;

struct people
{
    char id[19];   /* 身份证号码 */
    int social;    /* 社保缴纳月数 */
    int area;      /* 现有住房面积 */
    char date[11]; /* 申报日期 */
};
struct app
{
    string id;   /* 身份证号码 */
    int social;  /* 社保缴纳月数 */
    int area;    /* 现有住房面积 */
    string date; /* 申报日期 */
};
people *getMess(int &n);

int main()

{
    people *person; /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */
    int n;          /* n为报名人数，通过调用函数getMess获取 */
    person = getMess(n);
    vector<app> demandApplicants;  // 存储刚需条件的申请人,对于刚性需求，缴纳社保月数多者优先
    vector<app> improveApplicants; // 存储改进条件的申请人,对于改善性需求，现有自有住房面积小者优先
    for (int i = 0; i < n; i++)
    {
        string datestr = person[i].date; // 将char直接转string吧,顺便将MM-DD-YYYY转为YYYYMMDD
        string date = datestr.substr(6, 4) + datestr.substr(0, 2) + datestr.substr(3, 2);
        // 刚需：面积为0且社保大于24个月!要超过2年！这个边界条件特别重要，如果发现与结果差1可能就是这里有问题
        if (person[i].area == 0 && person[i].social > 24)
        {
            demandApplicants.push_back({string(person[i].id), person[i].social, person[i].area, date});
        }
        // 改进：面积大于0
        if (person[i].area > 0)
        {
            improveApplicants.push_back({string(person[i].id), person[i].social, person[i].area, date});
        }
    }
    delete[] person; // 释放内存
    // 对刚需申请人按社保月数降序排序，社保月数多者优先
    sort(demandApplicants.begin(), demandApplicants.end(), [](const app &a, const app &b)
         {
             if (a.social != b.social)
                 return a.social > b.social; // 社保月数多者优先
             return a.date < b.date;         // 日期早者优先
         });

    // 对改进申请人按现有住房面积升序排序，现有住房面积小者优先
    sort(improveApplicants.begin(), improveApplicants.end(), [](const app &a, const app &b)
         {
             if (a.area != b.area)
                 return a.area < b.area; // 现有住房面积小者优先
             return a.date < b.date;     // 日期早者优先
         });
    // 排序好后是让人们分类去不同组查找还是直接合并表查找？题目说优先刚需然后改进，那建立一个合并表是正确的
    vector<app> allApplicants;
    allApplicants.insert(allApplicants.end(), demandApplicants.begin(), demandApplicants.end());
    allApplicants.insert(allApplicants.end(), improveApplicants.begin(), improveApplicants.end());

    int m, T;
    cin >> m >> T;                              // 可供申请的套数以及查询的组数
    unordered_map<string, string> applicantMap; // 用于存储申请人ID和其结果，其实就是个结果表，哈希利于查找
    int i = 0;
    while (i < allApplicants.size())
    {
        int j = i;
        // 优先分配给刚需,其实这里就是处理排名相同的情况，想的比较复杂，先写上吧, 为这两个条件做准备
        // 3. 申请者符合购房条件，且该名次人数有多人，同时人数不大于所剩房源数量，则直接输出用空格分隔的两个整数，表示选房顺序号区间;
        // 4. 申请者符合购房条件，且该名次人数有多人，同时人数大于所剩房源数量，则输出用/分隔两个整数，如 A/B，表示 B 人中选 A 人，选房顺序为排名倒数 A 名范围。

        if (allApplicants[i].area == 0)
        {
            while (j + 1 < allApplicants.size() && allApplicants[j + 1].area == 0 && (allApplicants[j + 1].social == allApplicants[i].social && allApplicants[j + 1].date == allApplicants[i].date))
            {
                j++;
            }
            // 找到所有相同社保月数和日期的刚需申请人
        }
        else
        {
            // 这里就是处理改进
            while (j + 1 < allApplicants.size() && allApplicants[j + 1].area > 0 && (allApplicants[j + 1].area == allApplicants[i].area && allApplicants[j + 1].date == allApplicants[i].date))
            {
                j++;
            }
        }
        int groupSize = j - i + 1; // 计算当前组的大小
        int rank = i + 1;
        string resultstr;
        if (rank > m) // 如果排名超过可供申请的套数
        {
            resultstr = "Sorry";
        }
        else if (groupSize == 1)
        {
            resultstr = to_string(rank); // 如果组大小为1，直接输出排名
        }
        else if (groupSize <= m - rank + 1) // 如果组大小小于等于剩余房源数量
        {
            resultstr = to_string(rank) + " " + to_string(rank + groupSize - 1);
        }
        else // 如果组大小大于剩余房源数量
        {
            resultstr = to_string(m - rank + 1) + "/" + to_string(groupSize);
        }
        for (int k = i; k <= j; k++)
        {
            applicantMap[allApplicants[k].id] = resultstr; // 将申请人ID和结果存入哈希表
        }
        i = j + 1; // 移动到下一个组
    }
    while (T--)
    {
        string queryid;
        cin >> queryid; // 查询申请人ID
        if (applicantMap.find(queryid) != applicantMap.end())
        {
            cout << applicantMap[queryid] << endl; // 输出查询结果
        }
        else
        {
            cout << "Sorry" << endl; // 如果申请人不在结果表中，输出Sorry
        }
    }
    return 0;
}
people *getMess(int &n) /* 将文件数据读入内存 */
{
    FILE *fp;
    fp = fopen("house.bin", "rb");
    fseek(fp, -1 * (long)sizeof(int), 2);
    fread(&n, sizeof(int), 1, fp);
    rewind(fp);
    people *tmp = new people[n];
    fread(tmp, sizeof(people), n, fp);
    fclose(fp);
    return tmp;
}