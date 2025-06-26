/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30201
 *
 * [33] 搜索旋转排序数组
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find_target(nums, target, 0, nums.size() - 1);
    }
    int find_target(vector<int>& nums, int target, int lo, int hi) {
        if (!(lo <= hi)) return -1;
        if (lo == hi) return target == nums[lo]? lo: -1;
        int mid = lo + (hi-lo)/2;
        if (nums[mid] == target) return mid;
        int idx = -1;
        if (nums[lo] < nums[hi]) {
            // 找到的范围已经有序，直接找就行
            if (target < nums[lo]) return -1;
            if (target > nums[hi]) return -1;

            if (target > nums[mid]) return find_target(nums, target, mid+1, hi);
            return find_target(nums, target, lo, mid-1);
        } else {
            // case: 8,9,10,1,2,3 
            // 前半段有序, if mid = 2
            // 特殊情况，mid == hi 或者 mid == lo
            if (nums[lo] == nums[mid]) {
                return find_target(nums, target, mid+1, hi);
            }
            if (nums[hi] == nums[mid]) {
                return find_target(nums, target, lo, mid-1);
            } 
            if (nums[lo] < nums[mid]) {
                idx = find_target(nums, target, lo, mid-1);
                if (idx >= 0) return idx;
                return find_target(nums, target, mid+1, hi);
            } else if (nums[mid] < nums[hi]) {
                // 后半段有序, if mid = 3
                idx = find_target(nums, target, mid+1, hi);
                if (idx >= 0) return idx;
                return find_target(nums, target, lo, mid-1);
            } else {
                // not gonna happen
                return -2;
            }
        }
        return -1;
    }

};
// @lc code=end

int main() {
    Solution solution;
    vector<int> tmp({3,5,1});
    solution.search(tmp, 3);
    // your test code here
}



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

