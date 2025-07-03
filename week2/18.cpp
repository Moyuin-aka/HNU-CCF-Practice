#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solve()
{
    int N;
    std::cin >> N; // 只读一次，不用while循环

    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        std::string row_str;
        std::cin >> row_str;
        for (int j = 0; j < N; ++j)
        {
            grid[i][j] = row_str[j] - '0';
        }
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));

    // 计算 DP 表
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 行列号从1开始，所以实际位置是 (i+1, j+1)
            int row_num = i + 1;
            int col_num = j + 1;
            int expected_color = ((row_num + col_num) % 2 == 0) ? 1 : 0;

            if (grid[i][j] == expected_color)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    // 找最大值和数量
    int max_size = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            max_size = std::max(max_size, dp[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (dp[i][j] == max_size)
            {
                count++;
            }
        }
    }

    std::cout << max_size << " " << count << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}