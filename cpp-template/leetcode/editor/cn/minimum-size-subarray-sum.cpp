/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30201
 *
 * [209] 长度最小的子数组
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX, sz = 0;
        int left = 0, right = 0, total = 0;
        while (right < nums.size()) {
            total += nums[right++];
            sz++;
            while (total >= target) {
                minLen = min(minLen, sz);

                total -= nums[left++];
                sz--;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
