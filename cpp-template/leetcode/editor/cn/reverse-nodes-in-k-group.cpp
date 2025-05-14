/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30201
 *
 * [25] K 个一组翻转链表
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1)
            return head;
        ListNode dummy;
        ListNode *p = head;
        ListNode *tail = &dummy;

        while (tail != nullptr)
        {
            for (int i = 0; i < k - 1; i++)
            {
                if (p == nullptr)
                    break;
                p = p->next;
            }

            if (p != nullptr)
            {
                ListNode *tmp = p;
                p = p->next;
                tail = addreverse(tail, head, tmp);
                head = p;
            }
            else
            {
                tail->next = head;
                tail = nullptr;
            }
        }
        return dummy.next;
    }

    ListNode *addreverse(ListNode *cur, ListNode *head, ListNode *tail)
    {
        ListNode *newTail = head;
        ListNode *p = head;
        ListNode *end = tail->next;
        while (p != end)
        {
            ListNode *tmp = p;
            p = p->next;
            tmp->next = cur->next;
            cur->next = tmp;
        }

        return newTail;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    auto head = ListNode().createHead({1, 2, 3, 4, 5});

    solution.reverseKGroup(head, 2);
}

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
