/*
 * @lc app=leetcode.cn id=581 lang=cpp
 * @lcpr version=30201
 *
 * [581] 最短无序连续子数组
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
    int findUnsortedSubarray(vector<int>& nums) {
        // 数组可以被分为三部分，a,b,c
        // 其中 min(num_b) > max(a[i]), 且a为升序
        // max(num_b) < min(c[i]), 且c为升序
        int left = -1, right = -1;
        int _max = INT_MIN, _min = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= _max)
                _max = nums[i];
            else
                right = i;
        }
        for (int i = nums.size() - 1; i > -1; i--) {
            if (nums[i] <= _min)
                _min = nums[i];
            else
                left = i;
        }
        if (left == -1 && right == -1) return 0;

        return right - left + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,6,4,8,10,9,15]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
