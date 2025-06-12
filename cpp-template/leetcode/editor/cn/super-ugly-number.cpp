/*
 * @lc app=leetcode.cn id=313 lang=cpp
 * @lcpr version=30201
 *
 * [313] 超级丑数
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int64_t> dp(n + 1, INT_MAX), p(primes.size(), 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < primes.size(); j++) dp[i] = min(dp[i], dp[p[j]] * primes[j]);

            for (int j = 0; j < primes.size(); j++)
                if (dp[i] == dp[p[j]] * primes[j]) p[j]++;
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 12\n[2,7,13,19]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[2,3,5]\n
// @lcpr case=end

 */
