/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30201
 *
 * [102] 二叉树的层序遍历
 */

#include <iostream>
#include <vector>
#include <string>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        if (root != nullptr) q.push_back(root);
        vector<vector<int>> res;

        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                level.push_back(p->val);
                if (p->left != nullptr) q.push_back(p->left);
                if (p->right != nullptr) q.push_back(p->right);

                q.pop_front();
            }
            res.push_back(level);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

