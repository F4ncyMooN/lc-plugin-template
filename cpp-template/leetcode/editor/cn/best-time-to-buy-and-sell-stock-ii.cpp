/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=30201
 *
 * [122] 买卖股票的最佳时机 II
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
        // dp[i][j] 代表第i天，持有或者不持有股票的最大收益
        vector<vector<int>> dp(n + 1, vector(2, 0));
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int p = prices[i - 1];
            dp[i][0] = max(dp[i - 1][0],     // 昨天不持有，今天不买
                           dp[i - 1][1] + p  // 昨天持有，今天卖掉
            );
            dp[i][1] = max(dp[i - 1][0] - p,  // 昨天不持有，今天买
                           dp[i - 1][1]       // 昨天持有，今天不操作 或者 卖了再买
            );
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
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
