/*
 * @lc app=leetcode.cn id=113 lang=cpp
 * @lcpr version=30201
 *
 * [113] 路径总和 II
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int now = 0;
        traverse(root, targetSum, now, path);
        return res;
    }
    void traverse(TreeNode* root, int target, int& now, vector<int>& path) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);
        now += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (now == target) {
                res.push_back(path);
            }
            path.pop_back();
            now -= root->val;
            return;
        }
        if (root->left != nullptr) {
            traverse(root->left, target, now, path);
        }
        if (root->right != nullptr) {
            traverse(root->right, target, now, path);
        }
        path.pop_back();
        now -= root->val;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

 */
