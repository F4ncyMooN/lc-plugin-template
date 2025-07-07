/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30201
 *
 * [151] 反转字符串中的单词
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        vector<string> tmp;
        for (; r <= s.size(); r++) {
            // s[l, r)
            // embrace s[r] into window
            if (!(r == s.size() || s[r] == ' ')) {
                continue;
            }
            for (;; l++) {
                if (s[l] != ' ') break;
            }

            if (l < r) tmp.push_back(s.substr(l, r - l));
            l = r;
        }
        reverse(tmp.begin(), tmp.end());
        ostringstream res;
        bool is_start = true;

        for (auto t : tmp) {
            // s[l, r-1] is the word
            if (!is_start)
                res << ' ';
            else
                is_start = false;
            res << t;
        }
        return res.str();
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.reverseWords("  hello world  ");
    // your test code here
}

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
