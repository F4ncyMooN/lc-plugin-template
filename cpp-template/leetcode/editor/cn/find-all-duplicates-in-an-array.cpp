/*
 * @lc app=leetcode.cn id=442 lang=cpp
 * @lcpr version=30201
 *
 * [442] 数组中重复的数据
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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dups;
        unordered_map<int, int> tmp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 1 <= val <= n
            int val = nums[i];
            // in right position
            if (val - 1 == i) continue;
            if (nums[i] == nums[val - 1]) {
                tmp[val] = 1;
                continue;
            }
            swap(nums[i], nums[val - 1]);
            i--;
        }
        for (auto& [k, v] : tmp) {
            dups.push_back(k);
        }
        return dups;
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
    vector<int> arr({4, 3, 2, 7, 8, 2, 3, 1});
    solution.findDuplicates(arr);
    // your test code here
}

/*
// @lcpr case=start
// [4,3,2,7,8,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
