/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30201
 *
 * [2] 两数相加
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* p = &dummy;
        int result, overflow = 0;
        while (!(l1 == nullptr && l2 == nullptr)) {
            if (l1 == nullptr) {
                result = l2->val + overflow;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                result = l1->val + overflow;
                l1 = l1->next;
            } else {
                result = l1->val + l2->val + overflow;
                l1 = l1->next;
                l2 = l2->next;
            }
            overflow = 0;
            if (result > 9) {
                result -= 10;
                overflow = 1;
            }
            p->next = new ListNode(result);
            p = p->next;
        }
        if (overflow == 1) p->next = new ListNode(1);
        return dummy.next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
