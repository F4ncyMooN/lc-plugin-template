/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30201
 *
 * [152] 乘积最大子数组
 */

#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        // 以i位元素结尾的最大积
        vector<int> p(n + 1, 1);
        // 以i位元素结尾的最小积
        vector<int> _min(n + 1, 1);
        for (int i = 0; i < n; i++) {
            p[i + 1] = max({
                _min[i] * nums[i],
                p[i] * nums[i],
                nums[i],
            });
            _min[i + 1] = min({
                _min[i] * nums[i],
                p[i] * nums[i],
                nums[i],
            });
            res = max(res, p[i + 1]);
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
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */
