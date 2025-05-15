/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=30201
 *
 * [1004] 最大连续1的个数 III
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
    int longestOnes(vector<int>& nums, int k) {
        int flip = 0;
        int left = 0, right = 0;
        int res = INT_MIN;
        while (right < nums.size()) {
            int r = nums[right];
            if (r == 1) {
                res = max(res, right - left + 1);
                right++;
                continue;
            } else if (flip < k) {
                flip++;
                res = max(res, right - left + 1);
                right++;
                continue;
            } else {
            }
            while (flip == k && r == 0) {
                int l = nums[left];
                left++;

                if (l == 0) {
                    flip--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> array = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0,
                         1, 1, 0, 0, 0, 1, 1, 1, 1};
    solution.longestOnes(array, 3);
}

/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */
