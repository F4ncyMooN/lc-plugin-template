/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30200
 *
 * [90] 子集 II
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
    vector<vector<int>> result;
    vector<int> track;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        traverse(nums, -1);
        return result;
    }
    void traverse(vector<int> &nums, int picked)
    {
        result.push_back(track);
        int prev = -11;
        for (int i = picked + 1; i < nums.size(); i++)
        {
            if (prev == nums[i])
                continue;
            track.push_back(nums[i]);
            traverse(nums, i);
            track.pop_back();
            prev = nums[i];
        }
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
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
