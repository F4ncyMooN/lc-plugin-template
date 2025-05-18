/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30201
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& in, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;

        TreeNode* head = new TreeNode(pre[preStart]);
        int i = inStart;
        for (; i <= inEnd; i++) {
            if (head->val == in[i]) break;
        }
        int leftSize = i - inStart;

        head->left = build(pre, in, preStart + 1, preStart + leftSize, inStart, i - 1);
        head->right = build(pre, in, preStart + leftSize + 1, preEnd, i + 1, inEnd);
        return head;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
