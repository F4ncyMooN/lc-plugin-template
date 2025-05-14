/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30201
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return vector<int>({-1, -1});

        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        return vector<int>({left, right});
    }
    int left_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else if (nums[mid] == target)
            {
                r = mid - 1;
            }
        }
        if (l < 0 || l >= nums.size())
            return -1;
        return nums[l] == target ? l : -1;
    }
    int right_bound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else if (nums[mid] == target)
            {
                l = mid + 1;
            }
        }
        // 最后改成返回 left - 1
        if (l - 1 < 0 || l - 1 >= nums.size())
        {
            return -1;
        }
        return nums[l - 1] == target ? (l - 1) : -1;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
