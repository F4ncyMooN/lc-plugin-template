/*
 * @lc app=leetcode.cn id=221 lang=cpp
 * @lcpr version=30201
 *
 * [221] 最大正方形
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
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    continue;
                }
                int sub_max = dp[i + 1][j + 1];
                int size = 1;
                for (int k = 1; k < sub_max + 1; k++) {
                    if (matrix[i + k][j] == '1' && matrix[i][j + k] == '1')
                        size++;
                    else
                        break;
                }
                dp[i][j] = size;
                res = max(dp[i][j] * dp[i][j], res);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<char>> matrix({{'1'}});
    solution.maximalSquare(matrix);
    // your test code here
}

/*
// @lcpr case=start
//
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

 */
