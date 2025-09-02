/*
 * @lc app=leetcode.cn id=912 lang=cpp
 * @lcpr version=30202
 *
 * [912] 排序数组
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
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
    void qsort(vector<int>& nums, int lo, int hi) {
        if (hi <= lo) return;
        swap(nums[lo], nums[rand() % (hi - lo) + lo]);
        int left = partition_2way(nums, lo, hi);

        qsort(nums, lo, left - 1);
        qsort(nums, left + 1, hi);
    }
    int partition_2way(vector<int>& nums, int lo, int hi) {
        // 我这里把 i, j 定义为开区间，同时定义：
        // [lo, i) <= pivot；(j, hi] > pivot
        // 之后都要正确维护这个边界区间的定义
        int i = lo + 1, j = hi;
        int pivot = nums[lo];
        while (i <= j) {
            // 核心是把 == pivot的元素放到中间
            while (i <= hi && nums[i] <= pivot) i++;
            while (j >= lo && nums[j] > pivot) j--;
            if (i > j) break;

            // 此时 nums[i], nums[j]刚好乱序，swap
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
    int partition_simple_2way(vector<int>& nums, int lo, int hi) {
        // [lo+1, left] parts <= base
        int left = lo, base = nums[lo];
        // partition - simple 2 way
        for (int i = lo + 1; i <= hi; i++) {
            if (nums[i] <= base) swap(nums[++left], nums[i]);
        }
        swap(nums[lo], nums[left]);
        return left;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> nums({5, 1, 1, 2, 0, 0});
    solution.sortArray(nums);
}

/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */
