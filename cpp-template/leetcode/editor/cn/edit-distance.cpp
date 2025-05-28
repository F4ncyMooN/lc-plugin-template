/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30201
 *
 * [72] 编辑距离
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
        memo = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));

        return dp(word1, word2, word1.size() - 1, word2.size() - 1);
    }
    int dp(string word1, string word2, int i1, int i2) {
        if (i1 < 0 && i2 < 0) return 0;
        if (i1 < 0) return i2 + 1;
        if (i2 < 0) return i1 + 1;
        if (memo[i1][i2] != -1) return memo[i1][i2];

        if (word1[i1] == word2[i2])
            memo[i1][i2] = dp(word1, word2, i1 - 1, i2 - 1);
        else
            memo[i1][i2] = min({
                dp(word1, word2, i1, i2 - 1) + 1,      // insert one char into word1 exact same with word2
                dp(word1, word2, i1 - 1, i2 - 1) + 1,  // substitute char
                dp(word1, word2, i1 - 1, i2) + 1       //  delete from word1
            });
        return memo[i1][i2];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */
