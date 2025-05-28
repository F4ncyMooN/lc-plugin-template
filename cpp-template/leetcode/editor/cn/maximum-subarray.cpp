/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30201
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int>& nums) {
        // 选择 第 i 个字符的前n个字符，最大和
        vector<int> dp(nums.size() + 1, 0);
        int _max = INT_MIN;
        for (int i = 1; i <= nums.size(); i++) {
            int n = nums[i - 1];

            // 选了 n
            dp[i] = max(dp[i - 1] + n, n);
            _max = max(_max, dp[i]);
        }
        return _max;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
