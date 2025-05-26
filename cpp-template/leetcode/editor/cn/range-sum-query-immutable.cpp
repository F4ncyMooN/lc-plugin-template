/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30201
 *
 * [303] 区域和检索 - 数组不可变
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class NumArray {
   public:
    vector<int> pre_sum;
    NumArray(vector<int>& nums) {
        pre_sum.push_back(0);
        for (auto n : nums) pre_sum.push_back(*pre_sum.rbegin() + n);
    }

    int sumRange(int left, int right) { return pre_sum[right + 1] - pre_sum[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["NumArray", "sumRange", "sumRange", "sumRange"]\n[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]\n
// @lcpr case=end

 */
