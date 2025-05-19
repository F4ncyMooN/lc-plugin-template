/*
 * @lc app=leetcode.cn id=889 lang=cpp
 * @lcpr version=30201
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* build(vector<int>& pre, vector<int>& post, int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        if (preStart == preEnd) return new TreeNode(pre[preStart]);

        TreeNode* root = new TreeNode(pre[preStart]);

        int leftVal = pre[preStart + 1];

        int i = postStart;
        for (; i <= postEnd; i++) {
            if (post[i] == leftVal) break;
        }
        int left_size = i - postStart + 1;
        root->left = build(pre, post, preStart + 1, preStart + left_size, postStart, postStart + left_size - 1);
        root->right = build(pre, post, preStart + left_size + 1, preEnd, postStart + left_size, postEnd - 1);

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
// [1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */
