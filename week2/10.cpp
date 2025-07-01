#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
// 上边界 lower_bound,活用map
map<int,double>creditsMap={
    {100,4.0},
    {89,3.7},
    {84,3.3},
    {81,3.0},
    {77,2.7},
    {74,2.3},
    {71,2.0},
    {67,1.5},
    {63,1.0},
    {59,0.0},
};
double getCredits(int score){
    auto it = creditsMap.lower_bound(score);
    if(it == creditsMap.end()) return 0.0; // 如果没有找到合适的分数，返回0.0
    return it->second; // 返回对应的绩点
}
int main(){
    int n;
    cin>>n;
    vector<double>scores(n);
    double totalScores=0.0;
    for(int i=0;i<n;i++){
        cin>>scores[i];
        totalScores += scores[i]; // 计算所有课程学分之和
    }
    //总评绩点=所有学科绩点之和/所有课程学分之和
    // 一门课程的学分绩点=该课绩点*该课学分
    double totalPoints = 0.0;
    for(int i=0;i<n;i++){
        int score ;
        cin >> score;
        double credits = getCredits(score);
        totalPoints += credits * scores[i];
    }
    cout<<fixed<<setprecision(2)<<totalPoints/totalScores<<endl; // 输出总评绩点，保留两位小数
    return 0;
}