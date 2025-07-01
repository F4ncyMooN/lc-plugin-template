/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30201
 *
 * [82] 删除排序链表中的重复元素 II
 */

#include <iostream>
#include <vector>
#include <string>
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
        ListNode dummy(-200);
        ListNode *tail = &dummy, *p = head, *tmp = &dummy;
        bool is_dup = false;

        while (p != nullptr)
        {
            // dup
            if (tmp->val == p->val) {
                is_dup = true;
            } else if (tmp->val == -200) {
                tmp = p;
            } else if (is_dup) {
                tmp = p;
                is_dup = false;
            } else { 
                // tmp is unique val, link tmp to tail. note: Origin list is not maintained
                tail->next = tmp;
                tail = tail->next;
                tail->next = nullptr;
                // new tmp
                tmp = p;
            }
            p = p->next;
        }
        if (!is_dup && tmp->val != -200) {
            tail->next = tmp;
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
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

