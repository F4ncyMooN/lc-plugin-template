/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=30201
 *
 * [64] 最小路径和
 */

#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // dp[i, j] means min step from 0,0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = grid[i][j];

                if (i == 0 && j == 0) {
                    dp[i][j] = t;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + t;
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + t;
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + t;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
