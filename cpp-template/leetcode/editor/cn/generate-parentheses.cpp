/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30201
 *
 * [22] 括号生成
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
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s;
        deque<char> stack;
        traceback(s, stack, n);
        return res;
    }
    void traceback(string& s, deque<char>& stack, int n) {
        if (stack.size() == 0 && n == 0) {
            res.push_back(s);
            return;
        }
        if (stack.size() != 0) {  // add ')'
            stack.pop_back();
            s.push_back(')');
            traceback(s, stack, n);
            s.pop_back();
            stack.push_back('(');
        }
        if (n != 0) {  // add '('
            stack.push_back('(');
            s.push_back('(');
            traceback(s, stack, n - 1);
            s.pop_back();
            stack.pop_back();
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
