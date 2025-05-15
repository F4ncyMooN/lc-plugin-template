/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=30201
 *
 * [220] 存在重复元素 III
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int diff) {
        if (k == 0) return false;
        unordered_map<int, int> counts;
        int left = 0, right = 0;
        while (right < nums.size()) {
            int r = nums[right++];
            counts[r]++;
            for (int i = -diff; i <= diff; i++) {
                if (i == 0 && counts[r + i] == 2) return true;
                if (i != 0 && counts.count(r + i) && counts[r + i] == 1)
                    return true;
            }

            while (right - left == k + 1) {
                counts[nums[left]]--;
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */
