/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30201
 *
 * [200] 岛屿数量
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
    int num;
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        int num = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    flood(grid, i, j);
                }
            }
        }
        return num;
    }
    void flood(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();

        // out of boarder
        if (i == -1 || i == m || j == -1 || j == n)
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';

        flood(grid, i - 1, j);
        flood(grid, i + 1, j);
        flood(grid, i, j - 1);
        flood(grid, i, j + 1);
        return;
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
// [\n["1","1","1","1","0"],\n["1","1","0","1","0"],\n["1","1","0","0","0"],\n["0","0","0","0","0"]\n]\n
// @lcpr case=end

// @lcpr case=start
// [\n["1","1","0","0","0"],\n["1","1","0","0","0"],\n["0","0","1","0","0"],\n["0","0","0","1","1"]\n]\n
// @lcpr case=end

 */
