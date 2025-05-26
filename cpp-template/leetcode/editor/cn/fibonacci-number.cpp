/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30201
 *
 * [509] 斐波那契数
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
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> result(n + 1, 0);
        result[1] = 1;
        for (int i = 2; i <= n; i++) {
            result[i] = result[i - 1] + result[i - 2];
        }

        return result[n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
