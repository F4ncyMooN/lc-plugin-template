/*
 * @lc app=leetcode.cn id=395 lang=cpp
 * @lcpr version=30201
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int longestSubstring(string s, int k) {
        int res = 0;
        for (int require = 1; require <= 26; require++) {
            int satisfy = 0;
            int collect = 0;
            vector<int> counts(256, 0);
            for (int l = 0, r = 0; r < s.size(); r++) {
                counts[s[r]]++;

                if (counts[s[r]] == k) {
                    satisfy++;
                }
                if (counts[s[r]] == 1) {
                    collect++;
                }
                while (collect > require) {
                    counts[s[l]]--;
                    if (counts[s[l]] == k - 1) {
                        satisfy--;
                    }
                    if (counts[s[l]] == 0) {
                        collect--;
                    }
                    l++;
                }
                if (require == satisfy) {
                    res = max(res, r - l + 1);
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
// "aaabb"\n3\n
// @lcpr case=end

// @lcpr case=start
// "ababbc"\n2\n
// @lcpr case=end

 */
