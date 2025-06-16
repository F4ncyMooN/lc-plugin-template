/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30201
 *
 * [1] 两数之和
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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] == target) return {i, j};
        //     }
        // }
        // return {-1, -1};

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[nums[i]] = i;
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            if (mp.count(target - t) && mp[target - t] != i) return {i, mp[target - t]};
        }
        return {-1, -1};
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
