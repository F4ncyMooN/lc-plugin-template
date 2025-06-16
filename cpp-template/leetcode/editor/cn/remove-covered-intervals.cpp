/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 * @lcpr version=30201
 *
 * [1288] 删除被覆盖区间
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int left = intervals[0][0], right = intervals[0][1];
        int res = 1;
        for (auto& interval : intervals) {
            // cover this area
            if (left <= interval[0] and interval[1] <= right) {
                ;
            }
            // inter-section
            else if (left <= interval[0]) {
                res++;
                right = interval[1];
            }
            // not related
            else {
                left = interval[0];
                right = interval[1];
                res++;
            }
        }
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
// [[1,4],[3,6],[2,8]]\n
// @lcpr case=end

 */
