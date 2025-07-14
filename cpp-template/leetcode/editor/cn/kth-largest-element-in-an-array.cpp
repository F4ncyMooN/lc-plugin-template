/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30201
 *
 * [215] 数组中的第K个最大元素
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
    void quick(vector<int>& q, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        int x = q[mid];

        int i = l - 1, j = r + 1;
        while (i < j) {
            do i++;
            while (q[i] < x);
            do j--;
            while (q[j] > x);
            if (i < j) swap(q[i], q[j]);
        }
        quick(q, l, j);
        quick(q, j + 1, r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        quick(nums, 0, nums.size() - 1);  // 快速排序（从小到大）
        return nums[nums.size() - k];     // 获取第k大的元素 倒数第k个数的下标是（size-1-k+1）
    }
};

// @lc code=end

int main() {
    Solution solution;
    vector<int> tmp = {3, 2, 1, 5, 6, 4};
    solution.findKthLargest(tmp, 2);
    // your test code here
}

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
