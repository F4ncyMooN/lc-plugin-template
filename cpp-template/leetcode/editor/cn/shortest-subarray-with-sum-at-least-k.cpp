/*
 * @lc app=leetcode.cn id=862 lang=cpp
 * @lcpr version=30201
 *
 * [862] 和至少为 K 的最短子数组
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
    vector<int> pre_sum;
    int sum_between(int left, int right) { return pre_sum[right + 1] - pre_sum[left]; }
    int shortestSubarray(vector<int>& nums, int k) {
        pre_sum.push_back(0);
        int min_size = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            pre_sum.push_back(pre_sum[i] + nums[i]);
        }
        for (int left = 0, right = 0; right < nums.size(); right++) {
            // 从 [left, right] 之内的总和
            for (; left <= right && pre_sum[right + 1] - pre_sum[left] >= k; left++) {
                if (right >= left) min_size = min(min_size, right - left + 1);
            }
        }
        return min_size == INT_MAX ? -1 : min_size;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,2]\n3\n
// @lcpr case=end

 */
