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
    vector<char> choices(vector<vector<char>> &board, int i, int j)
    {
        vector<bool> options(9, true);
        // column+row
        for (int p = 0; p < 9; p++)
        {
            if (board[i][p] != '.')
                options[board[i][p] - '1'] = false;
            if (board[p][j] != '.')
                options[board[p][j] - '1'] = false;
        }

        // small 3*3
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < 3; l++)
            {
                auto c = board[3 * (i / 3) + k][3 * (j / 3) + l];
                if (c != '.')
                {
                    options[c - '1'] = false;
                }
            }
        }
        vector<char> ret;
        for (int p = 0; p < 9; p++)
        {
            if (options[p])
                ret.push_back('1' + p);
        }
        return ret;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> track;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    track.push_back(vector<int>{i, j});
                }
            }
        }
        backtrace(board, track);
    }
    void backtrace(vector<vector<char>> &board, vector<vector<int>> track)
    {
        if (track.size() == 0)
        {
            finished = true;
            return;
        }
        auto pos = track[track.size() - 1];
        int i = pos[0], j = pos[1];
        auto options = choices(board, i, j);

        for (auto c : options)
        {
            board[i][j] = c;
            track.pop_back();
            backtrace(board, track);
            if (finished)
            {
                break;
            }
            track.push_back(pos);
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
