/*
 * @lc app=leetcode.cn id=712 lang=cpp
 * @lcpr version=30201
 *
 * [712] 两个字符串的最小ASCII删除和
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
    int minimumDeleteSum(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] 意味着 word1[0..i] 和 word2[0..j] 的最少删除字符数
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return dp(word1, word2, m - 1, n - 1);
    }
    int dp(string& word1, string& word2, int i, int j) {
        int _sum = 0;
        if (i < 0)
            for (int p = 0; p <= j; p++) _sum += word2[p];
        if (j < 0)
            for (int p = 0; p <= i; p++) _sum += word1[p];
        if (i < 0 || j < 0) return _sum;

        if (memo[i][j] != -1) return memo[i][j];
        if (word1[i] == word2[j])
            memo[i][j] = dp(word1, word2, i - 1, j - 1);
        else
            memo[i][j] = min(dp(word1, word2, i - 1, j) + word1[i], dp(word1, word2, i, j - 1) + word2[j]);
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
// "delete"\n"leet"\n
// @lcpr case=end

 */
