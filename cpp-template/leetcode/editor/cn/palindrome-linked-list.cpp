/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30201
 *
 * [234] 回文链表
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
    bool is_loop = true;
    ListNode *pHead;
    bool isPalindrome(ListNode *head)
    {
        pHead = head;
        travel(head);
        return is_loop;
    }
    void travel(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        travel(head->next);
        if (head->val != pHead->val)
        {
            is_loop = false;
        }
        pHead = pHead->next;
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
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
