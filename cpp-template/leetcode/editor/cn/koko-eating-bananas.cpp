/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30201
 *
 * [875] 爱吃香蕉的珂珂
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
    long cost(vector<int> &piles, int k)
    {
        long hours = 0;
        for (auto p : piles)
        {
            hours += p / k + (p % k == 0 ? 0 : 1);
        }
        return hours;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        if (h < piles.size())
            return -1;
        int left = 1, right = 10000000000;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int hours = cost(piles, mid);
            if (hours > h)
            {
                left = mid + 1;
            }
            else if (hours < h)
            {
                right = mid - 1;
            }
            else if (hours == h)
            {
                right = mid - 1;
            }
        }
        // if (left - 1 <= 0)
        //     return 1;
        // if (cost(piles, left - 1) == h)
        //     return left - 1;
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
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */
