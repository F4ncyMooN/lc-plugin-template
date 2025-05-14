/*
 * @lc app=leetcode.cn id=967 lang=cpp
 * @lcpr version=30201
 *
 * [967] 连续差相同的数字
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> results;

    vector<int> numsSameConsecDiff(int n, int k)
    {
        for (int i = 1; i < 10; i++)
        {
            backtrace(i, n, k, 1);
        }
        return results;
    }
    void backtrace(int choice, int n, int k, int length)
    {
        if (length == n)
        {
            results.push_back(choice);
            return;
        }
        int digit = choice % 10;
        for (int i = 0; i < 10; i++)
        {
            if (abs(digit - i) != k || abs(i - digit) != k)
                continue;

            choice = choice * 10 + i;
            backtrace(choice, n, k, length + 1);
            choice /= 10;
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n0\n
// @lcpr case=end

// @lcpr case=start
// 2\n2\n
// @lcpr case=end

 */
