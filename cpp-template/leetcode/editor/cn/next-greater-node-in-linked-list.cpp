/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 * @lcpr version=30201
 *
 * [1019] 链表中的下一个更大节点
 */

#include <algorithm>
#include <iostream>
#include <list>
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
    vector<int> nextLargerNodes(ListNode* head) {
        // stk 保存着单调递减的数据，代表着还没找到next larger 的node的值
        stack<int> stk;
        stack<int> index;
        vector<int> res;
        int i = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            int val = p->val;
            // 如果当前值比栈顶要大，那么意味着栈内元素的下一个更大节点就是它
            while (stk.size() > 0 && val > stk.top()) {
                // 当前栈内元素所在的index所在的位置应该就是val
                res[index.top()] = val;
                stk.pop();
                index.pop();
            }
            stk.push(val);
            index.push(i);
            res.push_back(0);

            i++;
        }
        // 默认值已经输入给了res，所以不需要判断当前stk里面是否还有剩余元素。这些都是找不到下一个更大节点的。
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,4,3,5]\n
// @lcpr case=end

 */
