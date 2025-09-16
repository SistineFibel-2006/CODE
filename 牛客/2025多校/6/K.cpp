#include <iostream>
#include <vector>
#include <numeric> // For std::gcd (C++17)

// 函数：检查给定的 'g' 是否可能成为修改后数组的最终最大公约数
// 参数：
//   g：候选的最大公约数
//   n：数组的长度
//   a：输入整数数组
// 返回值：
//   如果 'g' 可以实现为最终的最大公约数，则返回 true；否则返回 false。
bool check(int g, int n, const std::vector<int>& a) {
    int first_bad_idx = -1; // 记录第一个不被 g 整除的元素的索引
    int last_bad_idx = -1;  // 记录最后一个不被 g 整除的元素的索引
    int common_remainder = -1; // 记录修改范围内元素模 g 的共同余数

    // 第一次遍历：找出所有不被 g 整除的元素，并检查它们是否具有相同的余数
    for (int i = 0; i < n; ++i) {
        int current_remainder = a[i] % g;
        if (current_remainder!= 0) {
            // 如果当前元素不被 g 整除
            if (first_bad_idx == -1) {
                first_bad_idx = i; // 记录第一个“坏”索引
            }
            last_bad_idx = i; // 更新最后一个“坏”索引

            if (common_remainder == -1) {
                common_remainder = current_remainder; // 设定预期的共同余数
            } else if (current_remainder!= common_remainder) {
                // 如果发现不同的非零余数，则无法通过单个 X 修正，g 不可能
                return false;
            }
        }
    }

    // 情况 1：所有元素都已经能被 g 整除
    if (first_bad_idx == -1) {
        // 这意味着所有 a[i] % g == 0。我们可以选择 X=0，任意范围，g 即可实现。
        return true;
    }

    // 情况 2：存在不被 g 整除的元素
    // 此时，我们推断出需要修改的连续子数组必须是 [first_bad_idx, last_bad_idx]。
    // 现在，我们需要验证这个推断：
    // 1. 检查推断范围 [first_bad_idx, last_bad_idx] 之外的元素是否都为 g 的倍数。
    // 2. 检查推断范围 [first_bad_idx, last_bad_idx] 之内的元素是否都具有相同的非零余数。
    //    （第二点已在第一次遍历中通过 common_remainder 检查完成）

    // 检查前缀部分（在 first_bad_idx 之前）
    for (int i = 0; i < first_bad_idx; ++i) {
        if (a[i] % g!= 0) {
            // 范围之外的元素不为 g 的倍数，g 不可能
            return false;
        }
    }

    // 检查后缀部分（在 last_bad_idx 之后）
    for (int i = last_bad_idx + 1; i < n; ++i) {
        if (a[i] % g!= 0) {
            // 范围之外的元素不为 g 的倍数，g 不可能
            return false;
        }
    }

    // 如果所有检查都通过，则存在一个有效的范围 [first_bad_idx, last_bad_idx]
    // 和一个非负整数 X (X = (g - common_remainder) % g)
    // 使得所有元素都成为 g 的倍数。
    return true;
}

int main() {
    // 优化 C++ 标准 I/O 流，提高速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T; // 测试数据组数
    std::cin >> T;
    while (T--) {
        int n; // 数组长度
        std::cin >> n;
        std::vector<int> a(n); // 存储数组元素
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // 特殊情况：如果数组只有一个元素，GCD 可以无限大，输出 0
        if (n == 1) {
            std::cout << 0 << "\n";
            continue;
        }

        // 对可能的 GCD 值进行二分搜索
        int low = 1;          // 最小可能的 GCD 是 1
        int high = 200000;    // 最大可能的 GCD 约为 2 * max(a_i) (10^5 + 10^5 - 1)
        int ans = 1;          // 存储找到的最大可实现 GCD

        while (low <= high) {
            int mid = low + (high - low) / 2; // 计算中间值，防止溢出
            if (check(mid, n, a)) {
                ans = mid;       // mid 是一个可实现的 GCD，尝试更大的值
                low = mid + 1;
            } else {
                high = mid - 1;  // mid 不可能，尝试更小的值
            }
        }
        std::cout << ans << "\n"; // 输出当前测试数据的最大 GCD
    }
    return 0;
}
