/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=30201
 *
 * [518] 零钱兑换 II
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        uint64_t n = coins.size();
        // 代表只使用前i个coin，凑成j的组合数
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(amount + 1, 0));
        // 使用任意coin，凑出 0 的个数， 啥也不干就行，直接设为1
        for (int i = 0; i < n + 1; i++) dp[i][0] = 1;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                int c = coins[i - 1];
                if (j - c >= 0)
                    // 假设使用这枚硬币, dp[i][j-c]是使用前i枚硬币凑出 j-当前硬币面额的方法
                    // 假设不使用这枚硬币，那么跟使用前i-1枚硬币，构造出 j的选择数一样
                    dp[i][j] = dp[i - 1][j] + dp[i][j - c];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
