/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30201
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        deque<int> process;
        for (const string& str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                auto right = *process.rbegin();
                process.pop_back();
                auto left = *process.rbegin();
                process.pop_back();

                if (str == "+") process.push_back(left + right);
                if (str == "-") process.push_back(left - right);
                if (str == "*") process.push_back(left * right);
                if (str == "/") process.push_back(left / right);
            } else {
                process.push_back(stoi(str));
            }
        }
        return *process.rbegin();
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
