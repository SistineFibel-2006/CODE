#include <iostream>
#include <vector>
#include <numeric>

// 使用 std::ios_base::sync_with_stdio(false); 和 std::cin.tie(NULL); 加速 I/O
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// 每个测试用例的解决函数
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    // 使用 vector<bool> 代替 bool 数组，更安全且可能更节省空间
    // 数组大小为 n+1，方便使用 1 到 n 的题号作为索引
    std::vector<bool> solved(n + 1, false);
    
    int solved_count = 0;
    
    for (int i = 0; i < m; ++i) {
        int p;
        std::cin >> p;
        
        // 如果题目 p 尚未被标记为解决
        if (!solved[p]) {
            solved[p] = true; // 标记为已解决
            solved_count++;   // 增加解决题目总数
        }
    }
    
    // 根据 S 的奇偶性计算差异
    // 如果 solved_count 是偶数, solved_count % 2 是 0
    // 如果 solved_count 是奇数, solved_count % 2 是 1
    int mismatches = solved_count - (solved_count % 2);
    
    std::cout << mismatches << std::endl;
}

int main() {
    // 加速 I/O
    fast_io();
    
    int t;
    std::cin >> t; // 读取测试用例数量
    while (t--) {
        solve();
    }
    
    return 0;
}