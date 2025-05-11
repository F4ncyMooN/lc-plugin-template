/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30201
 *
 * [47] 全排列 II
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
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        for (auto n : nums)
        {
            used.push_back(false);
        }
        sort(nums.begin(), nums.end());
        backtrace(nums);
        return results;
    }

    void backtrace(vector<int> &nums)
    {
        if (track.size() == nums.size())
        {
            results.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            if (i > 0 && used[i - 1] && nums[i] == nums[i - 1])
                continue;

            track.push_back(nums[i]);
            used[i] = true;

            backtrace(nums);

            used[i] = false;
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
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
