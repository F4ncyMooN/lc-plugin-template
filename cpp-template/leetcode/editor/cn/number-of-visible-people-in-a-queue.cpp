/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 * @lcpr version=30201
 *
 * [1944] 队列中可以看到的人数
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
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // lines 里面是递减的
        stack<int> lines;

        vector<int> res;
        for (auto h : heights) res.push_back(0);
        for (int i = heights.size() - 1; i >= 0; i--) {
            int cur = heights[i];

            while (lines.size() > 0 && cur > lines.top()) {
                res[i]++;
                lines.pop();
            }
            res[i] += lines.size() > 0 ? 1 : 0;
            lines.push(cur);
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
// [10,6,8,5,11,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,3,10]\n
// @lcpr case=end

 */
