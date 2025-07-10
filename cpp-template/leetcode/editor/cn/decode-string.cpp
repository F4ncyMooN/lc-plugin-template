/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30201
 *
 * [394] 字符串解码
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
    string decodeString(string s) {
        deque<int> stack;
        int i = 0;
        return _decode(s, stack, i);
    }
    string _decode(const string& s, deque<int>& stack, int& i) {
        int repeat = 0;
        string tmp;
        for (; i < s.size(); i++) {
            if ('a' <= s[i] && s[i] <= 'z')
                tmp.push_back(s[i]);
            else if ('0' <= s[i] && s[i] <= '9')
                repeat = repeat * 10 + (s[i] - '0');
            else if (s[i] == '[') {
                stack.push_back(repeat);
                repeat = 0;
                i++;
                tmp += _decode(s, stack, i);
                i--;
            } else if (s[i] == ']') {
                string t = tmp;
                int rp = stack.back();
                stack.pop_back();
                // repeat tmp
                for (int i = 0; i < rp - 1; i++) {
                    tmp += t;
                }
                i++;
                return tmp;
            }
        }
        return tmp;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.decodeString("3[a]2[bc]");
    // your test code here
}

/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */
