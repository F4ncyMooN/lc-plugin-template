/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 * @lcpr version=30201
 *
 * [1254] 统计封闭岛屿的数目
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        for (int j = 0; j < n; j++)
        {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1,1],\n[1,0,0,0,0,0,1],\n[1,0,1,1,1,0,1],\n[1,0,1,0,1,0,1],\n[1,0,1,1,1,0,1],\n[1,0,0,0,0,0,1],\n[1,1,1,1,1,1,1]]\n
// @lcpr case=end

 */
