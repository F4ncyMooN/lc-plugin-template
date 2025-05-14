/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=30201
 *
 * [567] 字符串的排列
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
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        int valid = 0;
        unordered_map<char, int> need, window;
        for (auto c : s1) {
            need[c]++;
        }

        while (right < s2.size()) {
            char c = s2[right];
            window[c]++;
            right++;
            if (need.count(c) && window[c] == need[c]) {
                valid++;
            }

            while (right - left >= s1.size()) {
                if (valid == need.size()) return true;

                char cl = s2[left];
                left++;
                if (need.count(cl) && window[cl] == need[cl]) {
                    valid--;
                }

                window[cl]--;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    solution.checkInclusion("ab", "eidbaooo");
}

/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */
