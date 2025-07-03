#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

// 定义一个结构体来存储论文的所有相关信息
struct Paper {
    std::string original_title;      // 原始标题，用于最后输出
    int citations;                   // 引用次数
    int original_index;              // 原始输入顺序，用于排序
    std::vector<std::string> words;  // 拆分并转为小写后的单词，用于搜索
};

// 辅助函数：将字符串转为小写
void to_lower(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
}

// 辅助函数：拆分字符串为单词并转为小写
std::vector<std::string> split_and_lower(const std::string& s) {
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> words;
    while (ss >> word) {
        to_lower(word);
        words.push_back(word);
    }
    return words;
}

void solve() {
    int N;
    while (std::cin >> N && N != 0) {
        // 1. 数据建模与预处理
        std::vector<Paper> papers;
        std::cin.ignore(); // 消耗掉 cin >> N 后留下的换行符

        for (int i = 0; i < N; ++i) {
            std::string title;
            std::getline(std::cin, title);
            
            int citations;
            std::cin >> citations;
            std::cin.ignore(); // 消耗 cin >> citations 后留下的换行符

            papers.push_back({
                title,
                citations,
                i, // 存储原始顺序
                split_and_lower(title)
            });
        }

        int M;
        std::cin >> M;
        std::cin.ignore();

        // 2. 查询处理
        for (int i = 0; i < M; ++i) {
            std::string query_line;
            std::getline(std::cin, query_line);
            std::vector<std::string> query_words = split_and_lower(query_line);

            std::vector<Paper> results;
            // 遍历所有论文，寻找匹配项
            for (const auto& paper : papers) {
                bool all_keywords_found = true;
                for (const auto& q_word : query_words) {
                    // C++20 的 a `std::vector::contains` 会更方便
                    // 这里我们用 std::find
                    if (std::find(paper.words.begin(), paper.words.end(), q_word) == paper.words.end()) {
                        all_keywords_found = false;
                        break; // 只要有一个关键词不匹配，就不是我们要的结果
                    }
                }

                if (all_keywords_found) {
                    results.push_back(paper);
                }
            }

            // 3. 结果排序
            std::sort(results.begin(), results.end(), [](const Paper& a, const Paper& b) {
                // 主规则：按引用次数降序
                if (a.citations != b.citations) {
                    return a.citations > b.citations;
                }
                // 次规则：按原始顺序升序
                return a.original_index < b.original_index;
            });

            // 4. 格式化输出
            for (const auto& paper : results) {
                std::cout << paper.original_title << std::endl;
            }
            std::cout << "***" << std::endl;
        }
        std::cout << "---" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}