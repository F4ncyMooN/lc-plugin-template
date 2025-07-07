/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30201
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* mid = find_mid(head);
        return merge(sortList(head), sortList(mid));
    }

    ListNode* find_mid(ListNode* head) {
        // at least this list has 1 nodes.
        ListNode *fast = head, *slow = head, *tmp;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        tmp = slow;
        slow = slow->next;
        tmp->next = nullptr;
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* p = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
            p->next = nullptr;
        }
        if (l1 != nullptr)
            p->next = l1;
        else
            p->next = l2;
        return dummy.next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    ListNode* head = ListNode::createHead({4, 2, 1, 3});
    solution.sortList(head);
    // your test code here
}

/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
