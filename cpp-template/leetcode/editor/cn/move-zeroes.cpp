/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30201
 *
 * [283] 移动零
 */

#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int lo = 0, hi = 0;
        // nums[lo, hi] is the range contains all zeros
        while (hi < nums.size()) {
            if (nums[hi] == 0) {
                hi++;
            } else {
                swap(nums[hi], nums[lo]);
                lo++;
                hi++;
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
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
