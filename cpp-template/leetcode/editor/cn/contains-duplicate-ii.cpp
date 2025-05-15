/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30201
 *
 * [219] 存在重复元素 II
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;
        unordered_map<int, int> counts;
        int left = 0, right = 0;
        while (right < nums.size()) {
            int r = nums[right++];
            counts[r]++;
            if (counts[r] >= 2) return true;

            while (right - left == k + 1) {
                counts[nums[left]]--;
                left++;
            }
        }
        for (auto n : counts) {
            if (n.second >= 2) return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> arr = {1, 2, 3, 1};
    solution.containsNearbyDuplicate(arr, 3);
}

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
