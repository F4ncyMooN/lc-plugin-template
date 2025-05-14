/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 * @lcpr version=30201
 *
 * [1011] 在 D 天内送达包裹的能力
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
    int f(vector<int> &weights, int capacity)
    {
        int days = 0;
        int k = capacity;
        for (auto w : weights)
        {
            if (w > capacity)
                return -1;
            if (k >= w)
            {
                k -= w;
            }
            else
            {
                days++;
                k = capacity;
                k -= w;
            }
        }
        return days + 1;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = 1, right = 500 * 5 * 10000;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            auto used_days = f(weights, mid);
            if (used_days == -1 || used_days > days)
            {
                left = mid + 1;
            }
            else if (used_days < days)
            {
                right = mid - 1;
            }
            else if (used_days == days)
            {
                right = mid - 1;
            }
        }
        return left;
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
// [1,2,3,4,5,6,7,8,9,10]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,4,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,1]\n4\n
// @lcpr case=end

 */
