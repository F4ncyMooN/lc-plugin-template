/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30201
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int num = 0;
    int kthSmallest(TreeNode* root, int k) {
        treeSize(root, k);
        return num;
    }
    int treeSize(TreeNode* root, int target) {
        if (root == nullptr) return 0;
        int left = treeSize(root->left, target);
        if (left == target - 1) {
            num = root->val;
        };
        int right = treeSize(root->right, target - left - 1);
        return left + right + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */
