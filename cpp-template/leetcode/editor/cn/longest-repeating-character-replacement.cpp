/*
 * @lc app=leetcode.cn id=424 lang=cpp
 * @lcpr version=30201
 *
 * [424] 替换后的最长重复字符
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
    int characterReplacement(string s, int k) {
        unordered_map<char, int> flips;
        int res = INT_MIN;
        for (auto c : s) {
            if (!flips.count(c)) {
                flips[c] = longestOnes(s, k, c);
                res = max(res, flips[c]);
            }
        }
        return res;
    }
    int longestOnes(string nums, int k, char c) {
        int flip = 0;
        int left = 0, right = 0;
        int res = INT_MIN;
        while (right < nums.size()) {
            char r = nums[right];
            if (r == c) {
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
            while (flip == k && r != c) {
                int l = nums[left];
                left++;

                if (l != c) {
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
}

/*
// @lcpr case=start
// "ABAB"\n2\n
// @lcpr case=end

// @lcpr case=start
// "AABABBA"\n1\n
// @lcpr case=end

 */
