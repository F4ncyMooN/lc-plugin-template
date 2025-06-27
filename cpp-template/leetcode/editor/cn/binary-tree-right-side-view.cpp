/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30201
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root){
        deque<TreeNode*> q;
        if (root != nullptr) q.push_back(root);
        vector<int> res;
        while (!q.empty())
        {
            int size = q.size();
            for (int i=0; i< size; i++) {
                auto n = q.front();
                if (i == size-1) res.push_back(n->val);
                if (n->left != nullptr) q.push_back(n->left);
                if (n->right != nullptr) q.push_back(n->right);

                q.pop_front();
            }
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
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

