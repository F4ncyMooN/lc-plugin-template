/*
 * @lc app=leetcode.cn id=402 lang=cpp
 * @lcpr version=30201
 *
 * [402] 移掉 K 位数字
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
    string removeKdigits(string num, int k) {
        stack<char> stk;
        stack<int> index;

        for (int i = 0; i < num.size(); i++) {
            char c = num[i];
            while (stk.size() > 0 && c < stk.top() && k > 0) {
                num[index.top()] = 0;
                index.pop();
                stk.pop();
                k--;
            }

            index.push(i);
            stk.push(c);
        }
        while (stk.size() > 0 && k > 0) {
            num[index.top()] = 0;
            index.pop();
            stk.pop();
            k--;
        }

        string res;
        for (char c : num) {
            if (c > 0) res.push_back(c);
        }
        if (res.size() == 0) res.push_back('0');
        if (res.size() == 1) return res;

        int left = res.find_first_not_of('0');
        if (left < 0) return "0";
        return res.substr(left, res.size() - left);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "1432219"\n3\n
// @lcpr case=end

// @lcpr case=start
// "10200"\n1\n
// @lcpr case=end

// @lcpr case=start
// "10"\n2\n
// @lcpr case=end

 */
