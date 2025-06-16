/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30201
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for (const auto& interval : intervals) {
            // inter-section
            if (interval[0] <= right) {
                right = max(interval[1], right);
            }
            // un-releated
            else {
                res.push_back({left, right});
                left = interval[0];
                right = interval[1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */
