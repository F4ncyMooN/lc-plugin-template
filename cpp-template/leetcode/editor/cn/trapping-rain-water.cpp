/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30201
 *
 * [42] 接雨水
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
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int n = height.size();
        int res = 0;
        // 数组充当备忘录
        vector<int> l_max(n);
        vector<int> r_max(n);
        // 初始化 base case
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        // 从左向右计算 l_max
        for (int i = 1; i < n; i++) l_max[i] = max(height[i], l_max[i - 1]);
        // 从右向左计算 r_max
        for (int i = n - 2; i >= 0; i--) r_max[i] = max(height[i], r_max[i + 1]);
        // 计算答案
        for (int i = 1; i < n - 1; i++) res += min(l_max[i], r_max[i]) - height[i];

        return res;
    }
};
// @lc code=end

int main() {
    printf("tests");
    Solution solution;
    vector<int> tmp = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("final is %d", solution.trap(tmp));
    // your test code here
}

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
