/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30201
 *
 * [20] 有效的括号
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    char convert(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        return 0;
    }
    bool isValid(string s) {
        deque<int> stk;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push_back(c);
            else {
                char expect = convert(c);
                if (stk.size() == 0) return false;
                if (*stk.rbegin() != expect) return false;
                stk.pop_back();
            }
        }
        return stk.size() == 0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */
