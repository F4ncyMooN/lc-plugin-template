/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30201
 *
 * [695] 岛屿的最大面积
 */

#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int res;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    flood(grid, i, j, area);
                }
            }
        }
        return res;
    }
    void flood(vector<vector<int>>& grid, int i, int j, int& area) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (grid[i][j] == 0) return;
        // flood self first
        grid[i][j] = 0;
        area++;
        flood(grid, i - 1, j, area);
        flood(grid, i + 1, j, area);
        flood(grid, i, j - 1, area);
        flood(grid, i, j + 1, area);

        res = max(res, area);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
//
\n[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */
