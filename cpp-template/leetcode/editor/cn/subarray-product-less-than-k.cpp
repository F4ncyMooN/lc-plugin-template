/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30201
 *
 * [713] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int left = 0, right = 0, res = 0;
        int product = 1;

        while (right < nums.size()) {
            int r = nums[right++];
            product *= r;

            while (product >= k && right > left) {
                int l = nums[left++];

                product /= l;
            }
            res += right - left;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */
