/*
 * @lc app=leetcode.cn id=140 lang=cpp
 * @lcpr version=30201
 *
 * [140] 单词拆分 II
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
    // key是s[0..j] 的所有可能 options string，按空格做分隔
    unordered_map<int, vector<string>> options;
    vector<string> wordBreak(string s, const vector<string>& wordDict) {
        if (wordDict.size() == 0) return {};
        if (dict.size() == 0) {
            for (const string& s : wordDict) dict[s] = s.size();
        }
        memo = vector<int>(s.size(), 666);
        can_split(s, s.size() - 1);
        return options[s.size() - 1];
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
                    if (split) {
                        if (j - size == -1)
                            options[j].push_back(word);
                        else {
                            for (auto it : options[j - size]) {
                                options[j].push_back(it + " " + word);
                            }
                        }
                    }
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
    // your test code here
}

/*
// @lcpr case=start
// "catsanddog"\n["cat","cats","and","sand","dog"]\n
// @lcpr case=end

// @lcpr case=start
// "pineapplepenapple"\n["apple","pen","applepen","pine","pineapple"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats","dog","sand","and","cat"]\n
// @lcpr case=end

 */
