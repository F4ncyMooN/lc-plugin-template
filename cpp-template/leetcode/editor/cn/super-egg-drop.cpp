/*
 * @lc app=leetcode.cn id=887 lang=cpp
 * @lcpr version=30201
 *
 * [887] 鸡蛋掉落
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
    vector<vector<int>> dp;
    int superEggDrop(int k, int n) {
        // dp[i][j] 代表使用i个鸡蛋，j层楼时，能确定f的最少操作次数
        // dp[1][j] = j
        dp.resize(k + 1, vector<int>(n + 1, -1));

        return find(k, n);
    }
    // 找k个鸡蛋，n层楼，一定能找到所需要的最少次数
    int find(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;
        if (dp[k][n] != -1) return dp[k][n];
        // 用二分搜索代替线性搜索
        int res = INT_MAX;
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // 鸡蛋在第 mid 层碎了和没碎两种情况
            int broken = find(k - 1, mid - 1);
            int not_broken = find(k, n - mid);
            // res = min(max(碎，没碎) + 1)
            if (broken > not_broken) {
                hi = mid - 1;
                res = min(res, broken + 1);
            } else {
                lo = mid + 1;
                res = min(res, not_broken + 1);
            }
        }
        dp[k][n] = res;
        return dp[k][n];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n
// @lcpr case=end

// @lcpr case=start
// 3\n14\n
// @lcpr case=end

 */
