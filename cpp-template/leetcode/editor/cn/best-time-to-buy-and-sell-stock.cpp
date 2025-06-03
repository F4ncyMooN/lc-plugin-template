/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30201
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> hold(n + 1, 0);
        vector<int> non_hold(n + 1, 0);
        hold[0] = INT_MIN;
        int profit = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int price = prices[i - 1];
            hold[i] = max(hold[i - 1], -price);
            non_hold[i] = max(hold[i - 1] + price, non_hold[i - 1]);
        }
        return non_hold[n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
