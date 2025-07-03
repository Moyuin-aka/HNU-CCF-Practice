#include <iostream>
#include <string>
#include <vector>
#include <numeric> // for std::accumulate, though not used here

void solve() {
    int n;
    while (std::cin >> n && n != 0) {
        // 每次循环前清空数据
        std::vector<char> team1_results;
        std::vector<char> team2_results;
        int team1_score = 0;
        int team2_score = 0;

        // 在读取 n 之后，需要忽略掉这一行结尾的换行符
        // 否则 getline 会立刻读到一个空行
        std::cin.ignore(); 

        for (int i = 0; i < n; ++i) {
            std::string line;
            std::getline(std::cin, line);

            // 检查这行是否以 "no good" 结尾
            // std::string::npos 表示没找到
            bool is_good = (line.find("no good") == std::string::npos);

            if (i % 2 == 0) { // 队伍1 (第 0, 2, 4... 个罚球)
                if (is_good) {
                    team1_results.push_back('O');
                    team1_score++;
                } else {
                    team1_results.push_back('X');
                }
            } else { // 队伍2 (第 1, 3, 5... 个罚球)
                if (is_good) {
                    team2_results.push_back('O');
                    team2_score++;
                } else {
                    team2_results.push_back('X');
                }
            }
        }

        // --- 开始输出 ---
        // 1. 输出表头
        int max_rounds = team1_results.size();
        for (int i = 1; i <= max_rounds; ++i) {
            std::cout << i << " ";
        }
        std::cout << "Score" << std::endl;

        // 2. 输出队伍1的记录
        for (size_t i = 0; i < team1_results.size(); ++i) {
            std::cout << team1_results[i] << (i == team1_results.size() - 1 ? "" : " ");
        }
        std::cout << " " << team1_score << std::endl;

        // 3. 输出队伍2的记录
        for (int i = 0; i < max_rounds; ++i) {
            if (i < team2_results.size()) {
                std::cout << team2_results[i];
            } else {
                // 如果队伍2没有罚第 i+1 轮，输出 '-'
                std::cout << '-';
            }
            // 控制空格
            if (i < max_rounds - 1) {
                std::cout << " ";
            }
        }
        std::cout << " " << team2_score << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}