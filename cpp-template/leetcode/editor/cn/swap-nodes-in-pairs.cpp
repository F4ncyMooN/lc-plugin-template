/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30201
 *
 * [24] 两两交换链表中的节点
 */

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode dummy;
        ListNode *p = &dummy, *next = head->next;
        while (head != nullptr) {
            next = head->next;
            if (next == nullptr) {
                p->next = head;
                head = head->next;
            } else {
                ListNode* tmp = next->next;  // save next head

                p->next = next;
                p = p->next;

                p->next = head;
                p = p->next;
                p->next = nullptr;
                head = tmp;
            }
        }
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
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
