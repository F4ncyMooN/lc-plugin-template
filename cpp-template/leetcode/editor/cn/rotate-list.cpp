/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30201
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy, *p = head, *next;
        int len = 1;
        if (head == nullptr || k == 0) return head;
        while (p->next != nullptr) {
            p = p->next;
            len++;
        }
        // make it a circle
        p->next = head;
        k = len - k % len;
        p = head;

        for (int i = 0; i < k - 1; i++) p = p->next;

        next = p->next;
        p->next = nullptr;
        return next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.rotateRight(ListNode::createHead({1, 2, 3, 4, 5}), 1);
    solution.rotateRight(ListNode::createHead({1, 2, 3, 4, 5}), 6);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

 */
