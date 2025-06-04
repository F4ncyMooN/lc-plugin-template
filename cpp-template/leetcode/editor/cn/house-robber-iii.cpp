/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30201
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        // rob this root
        vector<int> res = traverse(root);
        return max(res[0], res[1]);
    }
    // return {rob_root, not_rob_root}
    vector<int> traverse(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto rob_left = traverse(root->left);
        auto rob_right = traverse(root->right);

        return {
            rob_right[1] + rob_left[1] + root->val,  // if rob root, left & right both should not rob
            max(rob_left[0], rob_left[1]) + max(rob_right[0], rob_right[1])  // if not rob root,
        };
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
