/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=30201
 *
 * [8] 字符串转换整数 (atoi)
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
    int myAtoi(string o) {
        int i = 0;
        long res = 0;
        bool positive = true;
        // skip prefix ' '
        while (o[i] == ' ') i++;
        // test if has +/-, default is +
        if (o[i] == '+') {
            i++;
        } else if (o[i] == '-') {
            i++;
            positive = false;
        }

        // keep in mind overflow
        while (i < o.size() && o[i] >= '0' && o[i] <= '9') {
            res *= 10;
            res += o[i] - '0';
            if (positive && res > (long)INT_MAX) return INT_MAX;
            if (!positive && res - 1 > (long)INT_MAX) return INT_MIN;
            i++;
        }
        return positive ? res : -res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // cout << solution.myAtoi("+c") << endl;
    // cout << solution.myAtoi("c") << endl;
    // cout << solution.myAtoi("2147483647") << endl;
    // cout << solution.myAtoi("    -2147483647") << endl;
    cout << solution.myAtoi("-2147483648") << endl;
    cout << solution.myAtoi("-2222222222") << endl;
    // your test code here
}

/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */
