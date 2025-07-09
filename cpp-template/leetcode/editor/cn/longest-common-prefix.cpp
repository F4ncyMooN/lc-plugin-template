/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30201
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            common_prefix(res, strs[i]);
            if (res == "") return res;
        }
        return res;
    }
    void common_prefix(string& a, string& b) {
        int i = 0, n = a.size();
        for (; i < n; i++) {
            if (i >= b.size()) break;
            if (a[i] != b[i]) break;
        }
        for (; i < n; i++) {
            a.pop_back();
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<string> tmp({"abc", "abcd"});
    cout << solution.longestCommonPrefix(tmp);
    // your test code here
}

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
