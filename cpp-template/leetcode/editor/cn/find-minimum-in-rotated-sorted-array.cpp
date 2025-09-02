/*
 * @lc app=leetcode.cn id=153 lang=cpp
 * @lcpr version=30201
 *
 * [153] 寻找旋转排序数组中的最小值
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
    // 旋转数组的子数组也是旋转数组
    // 旋转数组的最右值一定 >= 当前数组的最小值，当前数组最小值 <= 最右
    // A..B..C 存在两种情况
    // B-1和B这里进行了旋转，B < C < A < B-1
    // 整体有序            A < B < C
    int findMin(const vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        // 保持区间以外一定不最小值
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // 如果比最右小，那么一定在左半边，为啥要-1呢？
            if (nums[mid] <= nums[n - 1]) {
                // 这个点比整体最右小，那么，要么这个值是最小值，要么最小值在它左侧
                hi = mid - 1;  // 每个数都不同，所以可以-1
            } else {
                // 这点比整体数组的最右还大，那么这个点之后一定有旋转点（之前一定不包含旋转点）
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.findMin({4, 1, 2, 1, 2});
    // your test code here
}

/*
// @lcpr case=start
// [3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,15,17]\n
// @lcpr case=end

 */
