/*
 * @lc app=leetcode.cn id=227 lang=cpp
 * @lcpr version=30201
 *
 * [227] 基本计算器 II
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
    int calculate(string s) {
        unordered_map<int, int> brackets;
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') stk.push(i);
            if (s[i] == ')') {
                int prev = stk.top();
                stk.pop();
                brackets[prev] = i;
            }
        }
        return _calc(s, 0, n - 1, brackets);
    }
    int _calc(const string &s, int start, int end, unordered_map<int, int> &bracket) {
        int i = start, n = 0;
        stack<int> stk;
        char sign = '+';
        while (i <= end) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '(') {
                n = _calc(s, i + 1, bracket[i] - 1, bracket);
                i = bracket[i] + 1;
            } else if (s[i] >= '0' && s[i] <= '9') {
                n = 10 * n + (s[i] - '0');
                i++;
            }

            if (i > end || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int prev;
                switch (sign) {
                    case '+':
                        stk.push(n);
                        break;
                    case '-':
                        stk.push(-1 * n);
                        break;
                    case '*':
                        prev = stk.top();
                        stk.pop();
                        stk.push(n * prev);
                        break;
                    case '/':
                        prev = stk.top();
                        stk.pop();
                        stk.push(prev / n);
                        break;
                    default:
                        break;
                }
                sign = s[i];
                n = 0;
                i++;
            }
        }
        while (stk.size() > 1) {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            stk.push(a + b);
        }
        return stk.top();
    }
};
// @lc code=end

int main() {
    Solution solution;
    cout << solution.calculate("42");
    // your test code here
}

/*
// @lcpr case=start
// "3+2*2"\n
// @lcpr case=end

// @lcpr case=start
// " 3/2 "\n
// @lcpr case=end

// @lcpr case=start
// " 3+5 / 2 "\n
// @lcpr case=end

 */
