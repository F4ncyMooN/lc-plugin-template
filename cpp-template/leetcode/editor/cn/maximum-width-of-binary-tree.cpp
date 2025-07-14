/*
 * @lc app=leetcode.cn id=662 lang=cpp
 * @lcpr version=30201
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        deque<pair<TreeNode*, u_int64_t>> q;
        q.push_back(make_pair(root, 0));
        u_int64_t res = 0;
        while (!q.empty()) {
            int size = q.size();
            u_int64_t left = __UINT_FAST64_MAX__, right = 0;
            for (int i = 0; i < size; i++) {
                auto [p, idx] = q.front();

                left = min(left, idx);
                right = max(right, idx);
                q.pop_front();
                if (size == 1) idx = 0;

                if (p->left != nullptr)
                    q.push_back(make_pair(p->left, idx * 2));
                if (p->right != nullptr)
                    q.push_back(make_pair(p->right, idx * 2 + 1));
            }
            res = max(res, right - left + 1);
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
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */
