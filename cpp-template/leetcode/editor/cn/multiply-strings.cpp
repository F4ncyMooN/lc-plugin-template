/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30201
 *
 * [43] 字符串相乘
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
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int overflow = 0;
        string res;

        for (int target = 0; target < m + n; target++) {
            int _sum = overflow;
            overflow = 0;

            for (int i = 0; i < m && i <= target; i++) {
                int j = target - i;
                if (j >= n) continue;
                int a = num1[m - i - 1] - '0';
                int b = num2[n - j - 1] - '0';
                _sum += a * b;
            }
            if (_sum > 9) {
                overflow = _sum / 10;
                _sum = _sum % 10;
            }
            res.push_back(_sum + '0');
        }

        if (overflow > 0) res.push_back(overflow + '0');
        // rm tailing '0'

        for (int i = res.size() - 1; i > 0; i--) {
            if (res[i] != '0') break;
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    cout << solution.multiply("123", "456");
    // your test code here
}

/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */
