/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30201
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) { return _isValidBST(root, nullptr, nullptr); }

    // 定义：该函数返回 root 为根的子树的所有节点是否满足 max->val > root->val > min->val
    bool _isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        // base case
        if (root == nullptr) return true;
        // 若 root->val 不符合 max 和 min 的限制，说明不是合法 BST
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        // 根据定义，限定左子树的最大值是 root->val，右子树的最小值是 root->val
        return _isValidBST(root->left, min, root) && _isValidBST(root->right, root, max);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
