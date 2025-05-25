/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 * @lcpr version=30201
 *
 * [1475] 商品折扣后的最终价格
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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> final_prices;
        // discounts 是个递增的栈
        stack<int> discounts;
        stack<int> index;

        for (int i = 0; i < prices.size(); i++) {
            int p = prices[i];

            while (discounts.size() > 0 && p <= discounts.top()) {
                final_prices[index.top()] -= p;

                discounts.pop();
                index.pop();
            }

            discounts.push(p);
            index.push(i);
            final_prices.push_back(p);
        }
        return final_prices;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [8,4,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [10,1,1,6]\n
// @lcpr case=end

 */
