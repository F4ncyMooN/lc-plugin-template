/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30201
 *
 * [143] 重排链表
 */

#include <algorithm>
#include <iostream>
#include <stack>
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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        deque<ListNode*> q;
        int size = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            q.push_back(p);
            size++;
        }

        ListNode dummy;
        ListNode *front = head, *tail = *q.rbegin(), *p = &dummy;

        for (int i = 0; i < (size + 1) / 2; i++) {
            if (front == tail) {
                p->next = front;
                p = p->next;
                p->next = nullptr;
            } else {
                p->next = front;
                front = front->next;
                p = p->next;

                p->next = tail;
                q.pop_back();
                tail = *q.rbegin();
                p = p->next;
                p->next = nullptr;
            }
        }
        head = dummy.next;
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
// [1,2,3,4,5]\n
// @lcpr case=end

 */
