/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=30201
 *
 * [1658] 将 x 减到 0 的最小操作数
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
    int minOperations(vector<int>& nums, int x) {
        long target = 0 - x;
        for (auto n : nums) {
            target += n;
        }
        int left = 0, right = 0;
        long cur = 0;
        int res = INT_MIN;
        while (right < nums.size()) {
            cur += nums[right++];

            while (cur > target && left < right) {
                cur -= nums[left++];
            }
            if (cur == target) {
                res = max(right - left, res);
            }
        }
        return res == INT_MIN ? -1 : nums.size() - res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> tmp = {1, 1};
    solution.minOperations(tmp, 5);
}

/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */
