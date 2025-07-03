#include <iostream>
#include <vector>
#include <algorithm>

struct Runner {
    int id, s, v;
};

void solve() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<Runner> runners(N);
    for (int i = 0; i < N; i++) {
        std::cin >> runners[i].s;
        runners[i].id = i + 1;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> runners[i].v;
    }
    
    std::vector<bool> infected(N, false);
    infected[K-1] = true;  // K是1-based，数组是0-based
    
    bool changed = true;
    while (changed) {
        changed = false;
        
        for (int i = 0; i < N; i++) {
            if (infected[i]) continue;
            
            for (int j = 0; j < N; j++) {
                if (!infected[j]) continue;
                
                bool can_meet = false;

                if (runners[i].s == runners[j].s) {
                    can_meet = true;
                } else if (runners[i].v != runners[j].v) {
                    double meet_time = (double)(runners[i].s - runners[j].s) / (runners[j].v - runners[i].v);
                    if (meet_time >= 0) {
                        can_meet = true;
                    }
                }
                // 如果起点不同且速度相同，永远不会相遇
                
                if (can_meet) {
                    infected[i] = true;
                    changed = true;
                    break;
                }
            }
        }
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (infected[i]) count++;
    }
    
    std::cout << count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}