/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30201
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        // dp[i] from 0 -> i, ends at i's longest valid sub-str
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') continue;
            // 考虑s[i-1], 只有两种情况，( or )
            if (s[i - 1] == '(') {
                dp[i] = i - 2 < 0 ? 2 : dp[i - 2] + 2;
            } else if (dp[i - 1] != 0) {  // s ends with xxxx))
                int len = dp[i - 1];
                if (i - 1 - len >= 0 && s[i - 1 - len] == '(')
                    dp[i] = dp[i - 1] + 2 +
                            (i - 1 - len - 1 >= 0 ? dp[i - 1 - len - 1] : 0);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    cout << solution.longestValidParentheses("(()") << endl;
    cout << solution.longestValidParentheses("()(())") << endl;
    cout << solution.longestValidParentheses(")()())") << endl;
    cout << solution.longestValidParentheses("((()()))") << endl;
    cout << solution.longestValidParentheses(")(((((()())()()))()(()))(")
         << endl;
    // your test code here
}

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
