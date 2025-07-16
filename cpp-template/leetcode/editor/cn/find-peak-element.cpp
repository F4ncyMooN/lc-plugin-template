/*
 * @lc app=leetcode.cn id=162 lang=cpp
 * @lcpr version=30201
 *
 * [162] 寻找峰值
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
    int res = 0;
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int lo = 0, hi = n - 1;
        while (true) {
            int mid = lo + (hi - lo) / 2;
            int minus_1 = nums[mid - 1], plus_1 = nums[mid + 1];
            if (nums[mid] > minus_1 && nums[mid] > plus_1) return mid;
            if (minus_1 > nums[mid])
                hi = mid;
            else
                lo = mid;
        }

        return 0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> tmp({1, 2, 3, 1});
    cout << solution.findPeakElement(tmp);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */
