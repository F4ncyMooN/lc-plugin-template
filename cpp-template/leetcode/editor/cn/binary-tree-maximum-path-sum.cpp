/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30201
 *
 * [124] 二叉树中的最大路径和
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
    unordered_map<TreeNode*, int> memo;
    int res = INT_MIN;

    int maxPathSum(TreeNode* root) {
        traverse(root);
        for (auto [n, total] : memo) {
            res = max(res, total);
        }
        return res;
    }
    int traverse(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        // root; left+root; right+root;
        memo[root] = max({
                         0,
                         left,
                         right,
                     }) +
                     root->val;

        res = max({res, root->val + left + right, memo[root]});
        return memo[root];
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
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */
