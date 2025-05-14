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
        int left = 0, right = 0;
        int unique = 0;
        int res = 0;
        unordered_map<char, int> window;
        while (right < s.size()) {
            char cr = s[right++];
            window[cr]++;
            if (window[cr] == 1) {
                unique++;
                res = max(unique, res);
            }

            while (right - left > unique) {
                char cl = s[left++];

                if (window[cl] == 1) {
                    unique--;
                }
                window[cl]--;
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
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
