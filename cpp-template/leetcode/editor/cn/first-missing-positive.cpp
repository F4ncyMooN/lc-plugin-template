/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30201
 *
 * [41] 缺失的第一个正数
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
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // put val into position val-1
            int val = nums[i];
            // out of box, keep it the same
            if (val <= 0 || val > n) continue;
            // in right position
            if (i == val - 1) continue;
            // no need to swap
            if (nums[val - 1] == val) continue;
            swap(nums[val - 1], nums[i]);
            i--;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) return i + 1;
            if (i != nums[i] - 1) return i + 1;
        }
        return n + 1;
    }
    void swap(int &a, int &b) {
        int t;
        t = a;
        a = b;
        b = t;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> arr({INT_MIN});
    solution.firstMissingPositive(arr);
}

/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */
