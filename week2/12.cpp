#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool edit(const string &test, const string &dict) // 判断是否一次编辑即可达到操作
{
    int len1 = test.length(), len2 = dict.length();
    if (abs(len1 - len2) > 1)
        return false;
    if (len1 == len2)
    {
        int diff = 0;
        for (int i = 0; i < len1; i++)
        {
            if (test[i] != dict[i])
            {
                diff++;
            }
        }
        return diff == 1;
    } // dict 比 test 一个字不同，字数相同，替换
    if (len1 + 1 == len2)
    { // 少了一个字，看看删掉是否会相同
        for (int i = 0; i < len2; i++)
        {
            string temp = dict.substr(0, i) + dict.substr(i + 1);
            if (temp == test)
            {
                return true;
            }
        }
        return false;
    }
    if (len1 == len2 + 1)
    { // 多了一个字，看看加上是否会相同
        for (int i = 0; i < len1; i++)
        {
            string temp = test.substr(0, i) + test.substr(i + 1);
            if (temp == dict)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    vector<string> dict;
    set<string> dict_set;
    while (cin >> word && word != "#")
    {
        dict.push_back(word);
        dict_set.insert(word);
    }
    vector<string> check;
    while (cin >> word && word != "#")
    {
        check.push_back(word);
    }
    for (const auto &test : check)
    {
        if (dict_set.find(test) != dict_set.end())
        {
            cout << test << " is correct" << endl;
        }
        else
        {
            vector<string> result;
            for (const auto &dict_word : dict)
            {
                if (edit(test, dict_word))
                {
                    result.push_back(dict_word);
                }
            }
            // sort(result.begin(), result.end());
            cout << test << ":";
            for (const auto &res : result)
            {
                cout << " " << res;
            }
            cout << endl;
        }
    }
    return 0;
}