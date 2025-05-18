/*
 * @lc app=leetcode.cn id=116 lang=cpp
 * @lcpr version=30201
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start

// // Definition for a Node.
// class Node {
//    public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
   public:
    Node* connect(Node* root) {
        queue<Node*> level;
        level.push(root);
        while (level.size() > 0) {
            for (int i = level.size(); i > 0; i--) {
                Node* p = level.front();
                level.pop();
                if (p == nullptr) continue;
                if (i == 1)
                    p->next = nullptr;
                else
                    p->next = level.front();

                if (p->left != nullptr) level.push(p->left);
                if (p->right != nullptr) level.push(p->right);
            }
        }
        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
