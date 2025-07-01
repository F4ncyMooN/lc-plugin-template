/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30201
 *
 * [54] 螺旋矩阵
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        //1 <= m, n <= 10
        int m = matrix[0].size();
        int n = matrix.size();

        int right_bound = m - 1, lower_bound = n - 1;
        int upper_bound = 0, left_bound = 0;
        // special cases:
        while(res.size() < m*n) {
            if (upper_bound <= lower_bound){
                for (int i = left_bound; i <= right_bound; i++) res.push_back(matrix[upper_bound][i]);
                upper_bound++;
            }
            if (right_bound >= left_bound) {
                for (int i = upper_bound; i <= lower_bound; i++) res.push_back(matrix[i][right_bound]);       
                right_bound--;         
            }
            if (upper_bound <= lower_bound){
                for (int i = right_bound; i >= left_bound; i--) res.push_back(matrix[lower_bound][i]);
                lower_bound--;
            }
            if (right_bound >= left_bound){
                for (int i = lower_bound; i >= upper_bound; i--) res.push_back(matrix[i][left_bound]);
                left_bound++;
            }
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
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

