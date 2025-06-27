/*
 * @lc app=leetcode.cn id=415 lang=cpp
 * @lcpr version=30201
 *
 * [415] 字符串相加
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int size = max(num1.size(), num2.size());

        deque<char> tmp;
        int added = 0;
        for (int i = 0; i<size; i++) {
            int l = num1.size()-i-1, r = num2.size()-i-1;
            int _sum = char_2_int(num1, l) + char_2_int(num2, r)+added;
            if (_sum > 9) {
                added = _sum / 10;
                _sum = _sum % 10;
            } else {
                added = 0;
            }
            tmp.push_front(_sum+'0');
        }
        if (added > 0) tmp.push_front('0'+added);

        if (tmp.empty()) return "0";
        string s;
        for (auto c: tmp) s.push_back(c);

        return s;
    }
    int char_2_int(string s, int idx) {
        if (idx < 0) return 0;
        return s[idx] - '0';
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// "11"\n"123"\n
// @lcpr case=end

// @lcpr case=start
// "456"\n"77"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n"0"\n
// @lcpr case=end

 */

