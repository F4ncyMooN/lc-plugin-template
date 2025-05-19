/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30201
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int postStart, int postEnd) {
        if (postStart > postEnd) return nullptr;
        int val = post[postEnd];
        TreeNode* root = new TreeNode(val);

        int i = inStart;
        for (; i <= inEnd; i++) {
            if (in[i] == val) break;
        }

        // left size is instart -> i-1, closive
        int left_size = i - inStart;
        // right size is i+1 -> inEnd, inclosive
        root->left = build(in, post, inStart, i - 1, postStart, postStart + left_size - 1);
        root->right = build(in, post, i + 1, inEnd, postStart + left_size, postEnd - 1);

        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> in = {4, 5, 2, 3, 1}, post = {4, 5, 2, 1, 3};
    solution.buildTree(in, post);
    // your test code here
}

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
