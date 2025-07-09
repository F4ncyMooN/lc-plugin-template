/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30201
 *
 * [110] 平衡二叉树
 */

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
