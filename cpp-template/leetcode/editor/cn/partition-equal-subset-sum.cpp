/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30201
 *
 * [416] 分割等和子集
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
    bool canPartition(vector<int>& nums) {
        int _sum = 0;
        for (auto n : nums) _sum += n;
        if (_sum % 2 == 1) return false;
        _sum /= 2;
        // 转换为使用nums 去填满 _sum这个背包
        int n = nums.size();
        // dp 代表着使用前i个数字去填满空间为j的背包是否可行
        vector<bool> dp(_sum + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = _sum; j > 0; j--) {
                int n = nums[i - 1];
                if (j - n >= 0)
                    // 如果选择了第i个数字，那么dp[i-1][j-n] 也就是使用前i-1个数字，也必须填满j-n的背包
                    // 如果不选第i个数字，那么dp[i-1][j] 使用前i-1个数字，也可以填满j
                    dp[j] = dp[j - n] || dp[j];
            }
        }
        return dp[_sum];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
