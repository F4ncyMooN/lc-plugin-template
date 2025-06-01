/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=30201
 *
 * [931] 下降路径最小和
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 2, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = dp[i][n + 1] = INT_MAX;

        int _min = INT_MAX;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min({
                    dp[i - 1][j - 1],
                    dp[i - 1][j],
                    dp[i - 1][j + 1],
                });
                dp[i][j] += matrix[i - 1][j - 1];

                if (i == m) {
                    _min = min(_min, dp[i][j]);
                }
            }
        }
        return _min;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */
