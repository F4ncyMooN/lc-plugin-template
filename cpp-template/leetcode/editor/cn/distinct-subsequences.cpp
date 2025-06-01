/*
 * @lc app=leetcode.cn id=115 lang=cpp
 * @lcpr version=30201
 *
 * [115] 不同的子序列
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
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        // dp[i][j]: t[0..i] 在 s[0..j] 中作为子序列出现了多少次
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i > j) {
                    dp[i][j] = 0;
                    continue;
                }
                char target = t[i - 1], source = s[j - 1];
                // 假设最后一个字符不相等，那么一定会归结到从source[0..j-1] 中找 target[0..i]
                // 那么这个问题其实相当于最后一个字符相等的时候，target [0..i-1] 作为source[0..j-1]的子序列数
                // eg：aba 在 bababa中作为子序列出现的次数 =
                // aba 在ba中出现的次数(0)
                // + aba 在baba中出现的次数(结尾相同) = ab 在 bab中出现的个数
                // + aba 在bababa中出现的次数(结尾相同) = ab 在babab中出现的个数
                if (source == target) {
                    // k代表source[0..k], source[0..0] 到 source[0..i]一定不满足题意
                    // source[0..k]
                    for (int k = i; k <= j; k++) {
                        if (s[k - 1] == target) dp[i][j] += dp[i - 1][k - 1];
                    }
                } else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        // O(M*(N*N))

        return dp[m][n];
    }
    int numDistinct2(string s, string t) {
        int m = s.size(), n = t.size();
        // 从s[0..i]中有dp[i][j]种包含t[0..j]的子序列
        vector<vector<uint64_t>> dp(m + 1, vector<uint64_t>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > i) {
                    dp[i][j] = 0;
                    continue;
                }
                char source = s[i - 1], target = t[j - 1];
                // 假设从bsa中找ba, 和从bs中找ba+从bs中找b
                if (source == target) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                // 从bab中找ba，子问题是从ba中找ba
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.numDistinct("rabbbit", "rabbit");
    // your test code here
}

/*
// @lcpr case=start
// "rabbbit"\n"rabbit"\n
// @lcpr case=end

// @lcpr case=start
// "babgbag"\n"bag"\n
// @lcpr case=end

 */
