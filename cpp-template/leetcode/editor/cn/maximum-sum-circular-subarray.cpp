/*
 * @lc app=leetcode.cn id=918 lang=cpp
 * @lcpr version=30201
 *
 * [918] 环形子数组的最大和
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
    int maxSubarraySumCircular(vector<int>& nums) {
        int _max = 0, _sum = 0;
        vector<int> pre_sum;
        for (int i = 0; i < nums.size() * 2; i++) pre_sum[i] = pre_sum[i - 1] + i == 0 ? 0 : nums[i % nums.size()];
        for (int left = 0, right = 0; right < nums.size() * 2; right++) {
            int cur_sum = pre_sum[right] - left == 0 ? 0 : pre_sum[left - 1];
            for (;; left++) {
            }
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2,2,-3]\n
// @lcpr case=end

 */
