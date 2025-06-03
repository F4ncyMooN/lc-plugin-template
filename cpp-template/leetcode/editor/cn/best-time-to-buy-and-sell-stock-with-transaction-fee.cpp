/*
 * @lc app=leetcode.cn id=714 lang=cpp
 * @lcpr version=30201
 *
 * [714] 买卖股票的最佳时机含手续费
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
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int p = prices[i - 1];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + p);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - p - fee);
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
// [1, 3, 2, 8, 4, 9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */
