/*
 * @lc app=leetcode.cn id=583 lang=cpp
 * @lcpr version=30201
 *
 * [583] 两个字符串的删除操作
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
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] 意味着 word1[0..i] 和 word2[0..j] 的最少删除字符数
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return dp(word1, word2, m - 1, n - 1);
    }
    int dp(string word1, string word2, int i, int j) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (memo[i][j] != -1) return memo[i][j];
        if (word1[i] == word2[j])
            memo[i][j] = dp(word1, word2, i - 1, j - 1);
        else
            memo[i][j] = min(dp(word1, word2, i - 1, j), dp(word1, word2, i, j - 1)) + 1;
        return memo[i][j];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "sea"\n"eat"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"etco"\n
// @lcpr case=end

 */
