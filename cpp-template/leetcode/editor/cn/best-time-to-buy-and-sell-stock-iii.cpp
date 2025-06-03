/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30201
 *
 * [123] 买卖股票的最佳时机 III
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
    int maxProfit(vector<int>& prices) { return maxProfitWithK(2, prices); }
    int maxProfitWithK(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;
        // 第i天，最多完成了j次交易，持有状态为k(0为不持有， 1为持有) 的最大利润
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        // bad cases
        for (int i = 0; i <= n - 1; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;  // not gonna happen
        }

        for (int i = 0; i <= n - 1; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];  // 刚开始，就买
                    continue;
                }
                // 假设今天不持有
                dp[i][j][0] = max(dp[i - 1][j][0],             // 昨天不持有，今天不操作
                                  dp[i - 1][j][1] + prices[i]  // 昨天持有，且今天卖出
                );

                // 假设今天持有
                dp[i][j][1] = max(dp[i - 1][j - 1][0] - prices[i],  // 昨天不持有，今天买入
                                  dp[i - 1][j][1]                   // 昨天持有，今天不动
                );
            }
        }

        return dp[n - 1][k][0];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
