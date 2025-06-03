/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30201
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int p = prices[i - 1];
            // 昨天不持有，今天也不持有；昨天持有，今天卖出
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + p);
            // 昨天持有，今天不动；前天不持有，昨天不持有，今天买入
            if (i == 1)
                dp[i][1] = -p;
            else
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - p);
        }
        return dp[n][0];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
