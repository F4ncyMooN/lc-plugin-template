/*
 * @lc app=leetcode.cn id=264 lang=cpp
 * @lcpr version=30201
 *
 * [264] 丑数 II
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
// #include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1, 1);
        int p_2 = 1, p_3 = 1, p_5 = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min({dp[p_2] * 2, dp[p_3] * 3, dp[p_5] * 5});
            if (dp[p_2] * 2 == dp[i]) p_2++;
            if (dp[p_3] * 3 == dp[i]) p_3++;
            if (dp[p_5] * 5 == dp[i]) p_5++;
        }
        return dp[n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    solution.nthUglyNumber(10);
}

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
