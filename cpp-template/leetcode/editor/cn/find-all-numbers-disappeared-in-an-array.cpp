/*
 * @lc app=leetcode.cn id=448 lang=cpp
 * @lcpr version=30201
 *
 * [448] 找到所有数组中消失的数字
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 1 <= val <= n
            int val = nums[i];
            if (val - 1 == i) continue;
            if (nums[val - 1] == nums[i]) continue;
            swap(nums[val - 1], nums[i]);
            i--;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 != i) res.push_back(i + 1);
        }
        return res;
    }
    void swap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4,3,2,7,8,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
