/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30200
 *
 * [77] 组合
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> results;
    vector<int> track;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(i + 1);
        }
        traverse(nums, k, -1);

        return results;
    }

    void traverse(vector<int> &nums, int k, int picked)
    {
        if (track.size() == k)
        {
            results.push_back(track);
            return;
        }

        for (int i = picked + 1; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            traverse(nums, k, i);
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
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
