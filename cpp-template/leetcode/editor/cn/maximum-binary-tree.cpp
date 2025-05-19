/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30201
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) { return build(nums, 0, nums.size() - 1); }
    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        // if (start == end) return new TreeNode(nums[start]);

        int maxIdx = start;
        int maxVal = INT_MIN;
        for (int i = start; i <= end; i++) {
            if (nums[i] > maxVal) {
                maxIdx = i;
                maxVal = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxVal);

        root->left = build(nums, start, maxIdx - 1);
        root->right = build(nums, maxIdx + 1, end);
        return root;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    solution.constructMaximumBinaryTree(nums);
}

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */
