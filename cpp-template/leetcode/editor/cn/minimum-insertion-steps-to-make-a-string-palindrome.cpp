/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 * @lcpr version=30201
 *
 * [1312] 让字符串成为回文串的最少插入次数
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
    int minInsertions(string s) {
        int n = s.size();
        if (n == 0) return 0;
        // s[i..j] 以内的最小插入次数
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // bad case: 如果i==j, 最小插入次数为0，如果i>j，不是一个字符串，不需要计算

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                char front = s[i - 1], end = s[j - 1];
                if (front == end)
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "zzazz"\n
// @lcpr case=end

// @lcpr case=start
// "mbadm"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */
