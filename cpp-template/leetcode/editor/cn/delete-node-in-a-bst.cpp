/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30201
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            // delete is ignored..
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                // swap root with root->right's min node and delete self
                TreeNode* minNode = findMin(root->right);
                root->right = deleteNode(root->right, minNode->val);
                minNode->left = root->left;
                minNode->right = root->right;

                root = minNode;
            }
        } else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
    TreeNode* findMin(TreeNode* root) {
        while (root->left != nullptr) root = root->left;
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
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
