/*
 * @lc app=leetcode.cn id=516 lang=cpp
 * @lcpr version=30201
 *
 * [516] 最长回文子序列
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
    int longestPalindromeSubseq(string s) {
        // 以 string[i..j] 是回文字串的最长长度
        int n = s.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // bad case: i==j，即有一个字符的一定是回文字串
        //           i> j，即字符串size为负的一定不是回文字串

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                char front = s[i - 1], end = s[j - 1];
                if (front == end)
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.longestPalindromeSubseq("bbbab");
    // your test code here
}

/*
// @lcpr case=start
// "bbbab"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
