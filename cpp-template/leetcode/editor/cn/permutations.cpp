/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30201
 *
 * [46] 全排列
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
    vector<int> used;
    vector<vector<int>> permute(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            used.push_back(0);
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
            if (used[i] == 1)
                continue;

            track.push_back(nums[i]);
            used[i] = 1;
            backtrace(nums);
            track.pop_back();
            used[i] = 0;
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
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
