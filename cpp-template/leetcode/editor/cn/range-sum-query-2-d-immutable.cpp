/*
 * @lc app=leetcode.cn id=304 lang=cpp
 * @lcpr version=30201
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class NumMatrix {
   public:
    vector<vector<long>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        preSum.push_back(vector<long>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            preSum.push_back(vector<long>(matrix[i].size() + 1, 0));
            for (int j = 0; j < matrix[i].size(); j++) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] + matrix[i][j] - preSum[i][j];
            }
        }
    }

    int sumRegion(int x1, int y1, int x2, int y2) {
        // 目标矩阵之和由四个相邻矩阵运算获得
        return preSum[x2 + 1][y2 + 1] - preSum[x1][y2 + 1] - preSum[x2 + 1][y1] + preSum[x1][y1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
//
["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */
