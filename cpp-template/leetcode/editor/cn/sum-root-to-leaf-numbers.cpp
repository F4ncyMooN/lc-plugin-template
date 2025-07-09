/*
 * @lc app=leetcode.cn id=129 lang=cpp
 * @lcpr version=30201
 *
 * [129] 求根节点到叶节点数字之和
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
    int64_t total = 0;
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        traverse(root, 0);
        return total;
    }
    void traverse(TreeNode* root, int64_t n) {
        n = n * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            total += n;
            return;
        }
        if (root->left != nullptr) traverse(root->left, n);
        if (root->right != nullptr) traverse(root->right, n);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */
