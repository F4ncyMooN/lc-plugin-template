/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30201
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int hl = 0, hr = 0;
        TreeNode* p = root;
        while (p != nullptr) {
            p = p->left;
            hl++;
        }
        p = root;
        while (p != nullptr) {
            p = p->right;
            hr++;
        }
        if (hl == hr) return pow(2, hl) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
