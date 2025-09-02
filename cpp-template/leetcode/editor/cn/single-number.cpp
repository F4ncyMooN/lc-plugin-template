/*
 * @lc app=leetcode.cn id=136 lang=cpp
 * @lcpr version=30201
 *
 * [136] 只出现一次的数字
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
    int singleNumber(const vector<int>& nums) {
        int res = 0;
        for (auto n : nums) {
            res ^= n;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    cout << solution.singleNumber({1});
    // your test code here
}

/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
