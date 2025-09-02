/*
 * @lc app=leetcode.cn id=154 lang=cpp
 * @lcpr version=30201
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1, last = nums[n - 1];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hi - lo <= 1) return min(nums[lo], nums[hi]);
            if (nums[mid] <= last) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,0,1]\n
// @lcpr case=end

 */
