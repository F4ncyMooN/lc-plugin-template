/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30201
 *
 * [76] 最小覆盖子串
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        unordered_map<char, int> need, window;
        for (auto c : t) need[c]++;
        int start = 0, end = INT_MAX;
        int valid = 0;
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            right++;
            if (need.count(c)) {
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (end == INT_MAX || end - start > right - left) {
                    start = left, end = right;
                }
                char t = s[left];
                if (need.count(s[left])) {
                    if (window[s[left]] == need[s[left]]) {
                        valid--;
                    }
                }
                window[s[left]]--;
                left++;
            }
        }
        return end == INT_MAX ? "" : s.substr(start, end - start);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    solution.minWindow("aa", "aa");
}

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
