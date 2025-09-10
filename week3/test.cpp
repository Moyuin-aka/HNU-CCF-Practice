#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string haveStr, needStr;
    if (!getline(cin, haveStr)) return 0;
    if (!getline(cin, needStr)) return 0;

    // 统计 ASCII 计数：题目颜色只在 0-9, a-z, A-Z，但用 256 更省事
    int have[256] = {0}, need[256] = {0};
    for (unsigned char c : haveStr) have[c]++;
    for (unsigned char c : needStr) need[c]++;

    int missing = 0;
    for (int c = 0; c < 256; ++c) {
        if (need[c] > have[c]) missing += (need[c] - have[c]);
    }

    if (missing == 0) {
        int extra = (int)haveStr.size() - (int)needStr.size();
        cout << "Yes " << extra << "\n";
    } else {
        cout << "No " << missing << "\n";
    }
    return 0;
}