/*
 * @lc app=leetcode.cn id=986 lang=cpp
 * @lcpr version=30201
 *
 * [986] 区间列表的交集
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        // 双指针
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < A.size() && j < B.size()) {
            int a1 = A[i][0], a2 = A[i][1];
            int b1 = B[j][0], b2 = B[j][1];
            // 两个区间存在交集
            if (b2 >= a1 && a2 >= b1) {
                // 计算出交集，加入 res
                res.push_back({max(a1, b1), min(a2, b2)});
            }
            // 指针前进
            if (b2 < a2) {
                j++;
            } else {
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<vector<int>> a = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> b = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    solution.intervalIntersection(a, b);
}

/*
// @lcpr case=start
// [[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,9]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[[4,8],[10,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,7]]\n[[3,10]]\n
// @lcpr case=end

 */
