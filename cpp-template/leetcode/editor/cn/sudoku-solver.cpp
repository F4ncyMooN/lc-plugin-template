/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30201
 *
 * [37] 解数独
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
    vector<vector<char>> track;
    bool finished;
    bool is_valid(vector<vector<char>> &board, int r, int c, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            // 判断行是否存在重复
            if (board[r][i] == num)
                return false;
            // 判断列是否存在重复
            if (board[i][c] == num)
                return false;
            // 判断 3 x 3 方框是否存在重复
            if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == num)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        backtrace(board, 0);
    }
    void backtrace(vector<vector<char>> &board, int index)
    {
        int i = index / 9, j = index % 9;

        if (finished)
            return;

        if (index >= 9 * 9)
        {
            finished = true;
            return;
        }
        if (board[i][j] != '.')
        {
            backtrace(board, index + 1);
            return;
        }
        for (char c = '1'; c <= '9'; c++)
        {
            if (!is_valid(board, i, j, c))
                continue;
            board[i][j] = c;
            backtrace(board, index + 1);
            if (finished)
            {
                break;
            }
            board[i][j] = '.';
        }
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
// \n[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
