/*
 * @lc app=leetcode.cn id=137 lang=cpp
 * @lcpr version=30201
 *
 * [137] 只出现一次的数字 II
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
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto n : nums) count[n]++;
        for (auto [n, cnt] : count) {
            if (cnt == 1) return n;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1,0,1,99]\n
// @lcpr case=end

 */
