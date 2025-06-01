/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30201
 *
 * [494] 目标和
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
    int findTargetSumWays(vector<int>& nums, int target) {
        // backtrace(nums, 0, target);
        // return result;

        // 设选了的集合为A，没选的是B sum(A)+sum(B) = _sum
        // 期望：sum(A) - sum(B) = target
        // 转化为有一种划分，可以将总价值变成(target+sum)/2
        int _sum = 0;
        for (int n : nums) _sum += n;
        if (_sum < abs(target) || (_sum + target) % 2 == 1) {
            return 0;
        }
        _sum = (_sum + target) / 2;
        // dp 意味着[0..i]个物品做了选择之后, 价值为j的选择数
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(_sum + 1, 0));
        // bad case
        dp[0][0] = 1;
        // for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= _sum; j++) {
                int n = nums[i - 1];
                if (j - n >= 0)  //  不选i   + 选了i, 可能数为
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - n];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][_sum];
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> tmp = {1, 1, 1, 1, 1};
    solution.findTargetSumWays(tmp, 3);
    // your test code here
}

/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
