/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30201
 *
 * [322] 零钱兑换
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
    vector<int> memo;
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return amount;
        if (amount < 0) return -1;
        if (memo.size() == 0) memo.resize(amount + 1);
        if (memo[amount] != 0) return memo[amount];

        int res = INT_MAX;
        for (auto c : coins) {
            int sub = coinChange(coins, amount - c);
            if (sub == -1) continue;
            res = min(res, sub + 1);
        }
        memo[amount] = res == INT_MAX ? -1 : res;

        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> t = {2147483647};
    solution.coinChange(t, 1);
    // your test code here
}

/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
