/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30200
 *
 * [39] 组合总和
 */

#include <iostream>
#include <algorithm>
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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        traverse(candidates, target, 0);

        return results;
    }
    void traverse(vector<int> &candidates, int target, int picked)
    {
        if (target == 0)
            results.push_back(track);
        if (target <= 0)
            return;

        for (int i = picked; i < candidates.size(); i++)
        {
            const auto c = candidates[i];
            track.push_back(c);
            traverse(candidates, target - c, i);
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
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
