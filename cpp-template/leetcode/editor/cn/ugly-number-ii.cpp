/*
 * @lc app=leetcode.cn id=264 lang=cpp
 * @lcpr version=30201
 *
 * [264] 丑数 II
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"
// #include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        int a = 1, b = 1, c = 1;
        int ugly = 1;
        for (int i = 0; i < n - 1; i++)
        {
            ugly = min({a * 2, b * 3, c * 5});
            // if (a * 2 <= b * 3 && a * 2 <= c * 5)
            // {
            //     ugly = a * 2;
            // }
            // else if (b * 3 <= a * 2 && b * 3 <= c * 5)
            // {
            //     ugly = b * 3;
            // }
            // else // (c * 5 <= a * 2 && c * 5 <= b * 3)
            // {
            //     ugly = c * 5;
            // }
            if (ugly == a * 2)
            {
                a++;
            }
            if (ugly == b * 3)
            {
                b++;
            }
            if (ugly == c * 5)
            {
                c++;
            }
        }
        return ugly;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
    solution.nthUglyNumber(12);
}

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
