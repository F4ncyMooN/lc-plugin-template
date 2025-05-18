/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30201
 *
 * [114] 二叉树展开为链表
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->left);
        flatten(root->right);

        // 现在，这个root的左右节点都已经拉成一个链表，需要翻转左右子树
        TreeNode* p = root->left;
        root->left = root->right;
        root->right = p;

        // 然后左子树接在右子树后面即可
        p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = root->left;
        root->left = nullptr;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<optional<int>> nodes{{1}, {2}, {5}, {3}, {4}, nullopt, {6}};
    TreeNode* head = TreeNode::createRoot(nodes);
    solution.flatten(head);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
