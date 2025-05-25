/*
 * @lc app=leetcode.cn id=901 lang=cpp
 * @lcpr version=30201
 *
 * [901] 股票价格跨度
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class StockSpanner {
   public:
    StockSpanner() {}

    int next(int price) {
        while (stk.size() > 0 && price >= stk.top()) {
            stk.pop();
            span.pop();
        }
        int prev_day = 0;
        if (stk.size() > 0) prev_day = span.top();
        stk.push(price);
        span.push(day);
        day++;
        return day - prev_day - 1;
    }

   private:
    stack<int> stk;
    stack<int> span;
    int day = 1;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]\n[[], [100], [80], [60], [70], [60], [75],
[85]]\n
// @lcpr case=end

 */
