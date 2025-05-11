/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30200
 *
 * [40] 组合总和 II
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
    vector<vector<int>> results;
    vector<int> track;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        traverse(candidates, target, -1);

        return results;
    }
    void traverse(vector<int> &nums, int target, int selected)
    {
        if (target == 0)
            results.push_back(track);
        if (target <= 0)
            return;

        for (int i = selected + 1; i < nums.size(); i++)
        {
            auto c = nums[i];
            if (nums.size() >= 2 && i > selected + 1 && nums[i] == nums[i - 1])
                continue;
            track.push_back(c);
            traverse(nums, target - c, i);
            track.pop_back();
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
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */
