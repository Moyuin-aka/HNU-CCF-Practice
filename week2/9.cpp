#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 这个题重要的就是定义比较吧，石头剪刀布，怎么比较呢……

enum class Gesture
{
    C, // 石头
    J, // 剪刀
    B  // 布
};
// 这里有一个天才想法，最后要按字母序决定放的最大值，那么我就字母序最小的放前面，这样后续比较的时候自动就是字母序小的优先
unordered_map<Gesture, int> win_map = {
    {Gesture::C, 1}, {Gesture::J, 2}, {Gesture::B, 0}};
struct gamer
{
    int win = 0;
    int lose = 0;
    int draw = 0;
    vector<int> win_count = {0, 0, 0}; // B, C, J
    Gesture gesture;
};
void judge(gamer &g1, gamer &g2)
{
    if (g1.gesture == g2.gesture)
    {
        g1.draw++;
        g2.draw++;
    }
    else if ((g1.gesture == Gesture::C && g2.gesture == Gesture::J) ||
             (g1.gesture == Gesture::J && g2.gesture == Gesture::B) ||
             (g1.gesture == Gesture::B && g2.gesture == Gesture::C))
    {
        g1.win++;
        g2.lose++;
        g1.win_count[win_map[g1.gesture]]++;
    }
    else
    {
        g1.lose++;
        g2.win++;
        g2.win_count[win_map[g2.gesture]]++;
    }
}
int main()
{
    int n;
    cin >> n;
    gamer g1, g2;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == "C")
            g1.gesture = Gesture::C;
        else if (s1 == "J")
            g1.gesture = Gesture::J;
        else
            g1.gesture = Gesture::B;

        if (s2 == "C")
            g2.gesture = Gesture::C;
        else if (s2 == "J")
            g2.gesture = Gesture::J;
        else
            g2.gesture = Gesture::B;

        judge(g1, g2);
    }
    cout << g1.win << " " << g1.draw << " " << g1.lose << endl;
    cout << g2.win << " " << g2.draw << " " << g2.lose << endl;
    // 找出胜利最多的那个手势，就找出最大值索引,解不唯一，则输出按字母序最小的解
    int max_g1 = distance(g1.win_count.begin(),
                          max_element(g1.win_count.begin(), g1.win_count.end()));
    int max_g2 = distance(g2.win_count.begin(),
                          max_element(g2.win_count.begin(), g2.win_count.end()));
    // 输出对应的手势
    char gestures[] = {'B', 'C', 'J'};
    cout << gestures[max_g1] << " " << gestures[max_g2];
    return 0;
}
