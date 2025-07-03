#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// 自定义电话号码比较器
// 1. 先按长度比较
// 2. 如果长度相等，再按字典序比较
struct ComparePhoneNumbers {
    bool operator()(const std::string& a, const std::string& b) const {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        return a < b;
    }
};

// C++17 兼容的 ends_with 实现
bool ends_with(const std::string& s, const std::string& suffix) {
    if (s.length() < suffix.length()) {
        return false;
    }
    return s.rfind(suffix) == (s.length() - suffix.length());
}

void solve() {
    int n;
    std::cin >> n;

    // 第一步：信息汇总 (这部分不变，用 set 去重很方便)
    std::map<std::string, std::set<std::string>> phonebook;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int count;
        std::cin >> name >> count;
        for (int j = 0; j < count; ++j) {
            std::string number;
            std::cin >> number;
            phonebook[name].insert(number);
        }
    }

    // 第二步：号码清洗与最终排序
    // 最终结果用 vector 存储，因为我们需要自定义排序
    std::map<std::string, std::vector<std::string>> cleaned_phonebook;
    
    for (const auto& pair : phonebook) {
        const std::string& name = pair.first;
        const std::set<std::string>& numbers = pair.second;
        
        std::vector<std::string> final_numbers;
        
        // 清洗逻辑不变
        for (const std::string& num_a : numbers) {
            bool is_redundant_suffix = false;
            for (const std::string& num_b : numbers) {
                if (num_a != num_b && ends_with(num_b, num_a)) {
                    is_redundant_suffix = true;
                    break;
                }
            }
            if (!is_redundant_suffix) {
                final_numbers.push_back(num_a);
            }
        }

        // *** 新增的关键步骤：使用自定义比较器进行排序 ***
        std::sort(final_numbers.begin(), final_numbers.end(), ComparePhoneNumbers());
        
        cleaned_phonebook[name] = final_numbers;
    }

    // 第三步：格式化输出 (这部分不变)
    std::cout << cleaned_phonebook.size() << std::endl;
    for (const auto& pair : cleaned_phonebook) {
        const std::string& name = pair.first;
        const std::vector<std::string>& numbers = pair.second;
        
        std::cout << name << " " << numbers.size();
        for (const std::string& num : numbers) {
            std::cout << " " << num;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}