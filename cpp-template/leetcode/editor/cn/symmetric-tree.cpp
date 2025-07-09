/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30201
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        bool all_null = false;
        while (!q.empty()) {
            int n = q.size();
            all_null = true;
            vector<TreeNode*> arr;
            for (int i = 0; i < n; i++) {
                auto p = q.front();
                if (p != nullptr) all_null = false;
                arr.push_back(p);
                q.pop_front();
                if (p == nullptr) {
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                } else {
                    q.push_back(p->left);
                    q.push_back(p->right);
                }
            }
            for (int i = 0, j = n - 1; i <= j; j--, i++) {
                if (arr[i] != nullptr && arr[j] != nullptr) {
                    if (arr[i]->val != arr[j]->val) return false;
                } else if (arr[i] != nullptr || arr[j] != nullptr) {
                    return false;
                }
            }
            if (all_null) break;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
