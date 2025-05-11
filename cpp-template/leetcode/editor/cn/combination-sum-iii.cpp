/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30201
 *
 * [216] 组合总和 III
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
    int max_depth;
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> nums;
        for (int i = 1; i <= 9; i++)
        {
            nums.push_back(i);
        }

        max_depth = k;
        backtrace(nums, n, -1);
        return results;
    }
    void backtrace(vector<int> &nums, int n, int prev_idx)
    {
        if (n == 0 && track.size() == max_depth)
            results.push_back(track);
        if (n <= 0 || track.size() == max_depth)
            return;

        for (int i = prev_idx + 1; i < nums.size(); i++)
        {
            auto c = nums[i];

            track.push_back(c);
            backtrace(nums, n - c, i);
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
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */
