/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30201
 *
 * [69] x 的平方根
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
    int mySqrt(int x) {
        int lo = 0, hi = x, ans = -1;
        // keep lo**2 <= x && hi**2 > x
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if ((int64_t)mid * mid <= x) {
                ans = mid;
                lo = mid + 1;

            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    solution.mySqrt(4);
}

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
