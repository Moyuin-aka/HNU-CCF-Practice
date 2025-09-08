#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
struct stu{
    string name;
    string id;
    int score;
};
int main(){
    int n;
    cin>>n;
    vector<stu> students(n);
    for(int i=0; i<n; i++){
        cin>>students[i].name>>students[i].id>>students[i].score;
    }
    sort(students.begin(), students.end(), [](const stu &a, const stu &b) {
        return a.score > b.score; // 按分数降序排序
    });
    cout<<students[0].name<<" "<<students[0].id<<endl; 
    cout<<students[n-1].name<<" "<<students[n-1].id<<endl; 
    return 0;
}