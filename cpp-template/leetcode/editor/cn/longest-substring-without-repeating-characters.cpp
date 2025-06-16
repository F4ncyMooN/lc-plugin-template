/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30201
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int left = 0, right = 0;
        unordered_map<char, int> counts;
        int res = INT_MIN;
        // window [left, right]
        for (; right < s.size(); right++) {
            char t = s[right];
            counts[t]++;

            for (; left <= right && (counts[t] > 1); left++) {
                counts[s[left]]--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    solution.lengthOfLongestSubstring("bbbbb");
}

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
