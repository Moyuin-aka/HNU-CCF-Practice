#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<char, string> standardMap = {{'C', "2"}, {'F', "3"}, {'I', "4"}, {'L', "5"}, {'O', "6"}, {'S', "7"}, {'V', "8"}, {'Y', "9"}, {'Z', ""}};

string toStandard(const string &s)
{
    string standard = "";
    for (char c : s)
    {
        if (isdigit(c))
        {
            standard += c;
        }
        else if (isupper(c))
        {
            auto it = standardMap.lower_bound(c);
            if (it != standardMap.end())
            {
                standard += it->second;
            }
        }
    }
    return standard;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string standard = toStandard(s);
        mp[standard]++;
    }
    for(const auto &pair : mp)
    {
        if (pair.second > 1)
        {
            cout<<pair.first.substr(0,3)<<"-"<<pair.first.substr(3)<<" "<<pair.second<<"\n";
        }
    }
    return 0;
}