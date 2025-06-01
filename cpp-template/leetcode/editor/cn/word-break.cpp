/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30201
 *
 * [139] 单词拆分
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
    unordered_map<string, int> dict;
    // s[0..j] 是否可以被拆分
    vector<int> memo;
    bool wordBreak(string s, const vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        if (dict.size() == 0) {
            for (const string& s : wordDict) dict[s] = s.size();
        }
        memo = vector<int>(s.size(), 666);

        return can_split(s, s.size() - 1);
    }
    bool can_split(const string& s, int j) {
        if (j + 1 <= 0) return true;
        if (memo[j] != 666) return memo[j];

        bool split = false;
        for (auto& [word, size] : dict) {
            if (size > j + 1) {
                continue;
            } else {
                auto sub = s.substr(j + 1 - size, size);
                if (sub == word) {
                    split |= can_split(s, j - size);
                    if (split) break;
                }
            }
        }
        memo[j] = split;
        return split;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.wordBreak("leetcode", {"leet", "code"});
    // your test code here
}

/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */
