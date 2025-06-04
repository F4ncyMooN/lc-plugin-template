/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30201
 *
 * [198] 打家劫舍
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // 偷窃了第i家的最最高金额
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int money = nums[i - 1];
            if (i - 2 < 0)
                dp[i] = money;
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + money);
        }
        return max(dp[n], dp[n - 1]);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */
