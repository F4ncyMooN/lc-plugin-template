/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30201
 *
 * [92] 反转链表 II
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode dummy;
        int i = 1;
        ListNode *p = head;
        ListNode *tail = &dummy;
        head = &dummy;
        while (p != nullptr)
        {
            if (i < left || i > right)
            {
                tail->next = p;
                tail = tail->next;
                head = head->next;

                p = p->next;
                tail->next = nullptr;
            }
            else
            {
                ListNode *cur = p;
                if (head == tail)
                {
                    tail = p;
                }
                p = p->next;
                cur->next = head->next;
                head->next = cur;
            }
            i++;
        }

        return dummy.next;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
