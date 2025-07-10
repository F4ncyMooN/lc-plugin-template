/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30201
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p != nullptr) {
            if (p->next == nullptr) {
                p = p->next;
            } else if (p->next->val == p->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }

        return head;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */
