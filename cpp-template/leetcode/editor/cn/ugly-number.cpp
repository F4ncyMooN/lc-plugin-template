/*
 * @lc app=leetcode.cn id=263 lang=cpp
 * @lcpr version=30201
 *
 * [263] 丑数
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
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (int k : {2, 3, 5}) {
            while (n % k == 0) n /= k;
        }
        return n == 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
