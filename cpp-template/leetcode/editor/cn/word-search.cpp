/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30201
 *
 * [79] 单词搜索
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
    unordered_map<string, bool> cache;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool found = find(board, i, j, word, 0);
                if (found) return true;
            }
        }
        return false;
    }
    bool find(vector<vector<char>>& board, int i, int j, string& word, int pos) {
        if (board[i][j] != word[pos]) return false;
        if (pos == word.size() - 1) return true;
        board[i][j] = -board[i][j];
        auto fn = [&board, &word, pos, this](int x, int y) {
            if (x == -1 || x == board.size()) return false;
            if (y == -1 || y == board[0].size()) return false;
            return find(board, x, y, word, pos + 1);
        };
        bool found = fn(i - 1, j) || fn(i + 1, j) || fn(i, j - 1) || fn(i, j + 1);
        board[i][j] = -board[i][j];

        return found;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
