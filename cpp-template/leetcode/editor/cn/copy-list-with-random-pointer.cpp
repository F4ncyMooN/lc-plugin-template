/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30201
 *
 * [138] 随机链表的复制
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> link;
        for (Node* p = head; p != nullptr; p = p->next) {
            link[p] = new Node(p->val);
        }
        for (Node* p = head; p != nullptr; p = p->next) {
            Node* newP = link[p];
            newP->next = link[p->next];
            newP->random = link[p->random];
        }
        return link[head];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */
