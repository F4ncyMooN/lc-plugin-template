/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30201
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[i][j] 代表从 i 到 j是不是回文字串
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (i == j) dp[i][j] = 1;

        int _max = INT_MIN;
        string t = s.substr(0, 1);
        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= i; j--) {
                if (i == j) continue;
                if (s[i - 1] != s[j - 1]) continue;
                if ((i + 1 <= n && j - 1 >= 0 && dp[i + 1][j - 1] != -1) || abs(i - j) == 1) {
                    dp[i][j] = j - i + 1;
                    if (dp[i][j] > _max) {
                        t = s.substr(i - 1, j - i + 1);
                        _max = dp[i][j];
                    }
                }
            }
        }
        return t;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    solution.longestPalindrome("baad");
}

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
