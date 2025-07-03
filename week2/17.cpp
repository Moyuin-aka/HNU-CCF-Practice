#include <iostream>
#include <vector>
#include <string>

void solve() {
    long long N, A, B, C;
    while (std::cin >> N >> A >> B >> C) {
        // 1. 游戏准备：解析棋盘
        std::vector<int> board(N);
        for (int i = 0; i < N; ++i) {
            std::string s;
            std::cin >> s;
            if (s == "N") {
                board[i] = -1; // -1 代表普通格子
            } else {
                // "GX" -> 提取 X
                board[i] = std::stoi(s.substr(1));
            }
        }

        // 玩家位置：player_pos[0] for Lele, player_pos[1] for Yueyue
        std::vector<int> player_pos(2, 0); 
        long long last_dice_val = C; // F-1 初始值设为 C
        int turn = 0;

        // 2. 游戏循环
        while (true) {
            int current_player = turn % 2;
            
            // a. 算骰子
            long long dice_val = (A * last_dice_val + B) % 6 + 1;
            last_dice_val = dice_val;

            // b. 移动
            int current_pos = player_pos[current_player];
            int new_pos = current_pos + dice_val;

            // c. 撞墙反弹
            if (new_pos >= N) {
                new_pos = (N - 1) - (new_pos - (N - 1));
            }

            // d. 坐飞机 (可能连环飞)
            while (board[new_pos] != -1) {
                new_pos = board[new_pos];
            }

            // 更新玩家位置
            player_pos[current_player] = new_pos;

            // f. 判胜 (在踢人之前判断，因为题目说走到就算赢)
            if (new_pos == N - 1) {
                if (current_player == 0) {
                    std::cout << "Lele" << std::endl;
                } else {
                    std::cout << "Yueyue" << std::endl;
                }
                break; // 游戏结束
            }

            // e. 踢人
            int other_player = 1 - current_player;
            if (new_pos != 0 && new_pos == player_pos[other_player]) {
                player_pos[other_player] = 0;
            }

            // 进入下一回合
            turn++;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}