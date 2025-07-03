#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        std::string row_str;
        std::cin >> row_str;
        for (int j = 0; j < N; ++j) {
            grid[i][j] = row_str[j] - '0';
        }
    }

    std::vector<std::vector<int>> dp1(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> dp2(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int row_num = i + 1;
            int col_num = j + 1;
            int sum_pos = row_num + col_num;
            int expected1 = (sum_pos % 2 == 0) ? 1 : 0;
            int expected2 = (sum_pos % 2 == 0) ? 0 : 1;

            if (grid[i][j] == expected1) {
                if (i == 0 || j == 0) {
                    dp1[i][j] = 1;
                } else {
                    dp1[i][j] = 1 + std::min({dp1[i-1][j], dp1[i][j-1], dp1[i-1][j-1]});
                }
            } else {
                dp1[i][j] = 0;
            }

            if (grid[i][j] == expected2) {
                if (i == 0 || j == 0) {
                    dp2[i][j] = 1;
                } else {
                    dp2[i][j] = 1 + std::min({dp2[i-1][j], dp2[i][j-1], dp2[i-1][j-1]});
                }
            } else {
                dp2[i][j] = 0;
            }
        }
    }

    int max_size = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            max_size = std::max(max_size, dp1[i][j]);
            max_size = std::max(max_size, dp2[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp1[i][j] == max_size) {
                count++;
            }
            if (dp2[i][j] == max_size) {
                count++;
            }
        }
    }

    std::cout << max_size << " " << count << std::endl;
    return 0;
}