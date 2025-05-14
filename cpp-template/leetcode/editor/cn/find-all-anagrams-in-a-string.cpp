/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30201
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s2, string s1) {
        int left = 0, right = 0;
        int valid = 0;
        unordered_map<char, int> need, window;
        vector<int> res;
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
                if (valid == need.size()) res.push_back(left);

                char cl = s2[left];
                left++;
                if (need.count(cl) && window[cl] == need[cl]) {
                    valid--;
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
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
