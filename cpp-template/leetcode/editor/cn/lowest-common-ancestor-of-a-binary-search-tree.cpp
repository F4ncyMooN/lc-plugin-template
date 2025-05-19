/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30201
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
   public:
    TreeNode* lca = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        int small = min(p->val, q->val);
        int big = max(p->val, q->val);
        if (root->val == small || root->val == big) return root;
        if (small < root->val && root->val < big) {
            lca = root;
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (lca != nullptr) return lca;

        if (left != nullptr && right != nullptr) {
            lca = root;
            return root;
        }
        if (left != nullptr) return left;
        if (right != nullptr) return right;
        return nullptr;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */
