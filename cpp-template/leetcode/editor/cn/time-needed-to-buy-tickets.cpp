/*
 * @lc app=leetcode.cn id=2073 lang=cpp
 * @lcpr version=30201
 *
 * [2073] 买票需要的时间
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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<ListNode*> q;
        ListNode* target = nullptr;
        for (int i = 0; i < tickets.size(); i++) {
            auto person = new ListNode(tickets[i]);
            if (i == k) target = person;
            q.push(person);
        }
        int n = 0;
        while (q.size() != 0) {
            auto top = q.front();
            q.pop();
            if (top->val == 1) {
                if (top == target) {
                    delete top;
                    return n + 1;
                }
                delete top;

            } else {
                top->val--;
                q.push(top);
            }
            n++;
        }
        return n;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> tickets({2, 3, 2});
    solution.timeRequiredToBuy(tickets, 2);
}

/*
// @lcpr case=start
// [2,3,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,1]\n0\n
// @lcpr case=end

 */
