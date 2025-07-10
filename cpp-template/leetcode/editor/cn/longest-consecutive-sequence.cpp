/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30201
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> map;
        unordered_map<int, int> visited;
        for (auto n : nums) map[n] = 1;
        int res = 0;
        for (auto n : nums) {
            res = max(res, _helper(map, visited, n));
        }
        return res;
    }
    int _helper(unordered_map<int, int> &map, unordered_map<int, int> &visit,
                int n) {
        // wants to find longest consecutive from n
        if (visit.count(n)) return visit[n];
        if (map.count(n)) {
            int t = _helper(map, visit, n + 1);
            visit[n] = t + 1;
            return visit[n];
        }
        return 0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> arr({100, 4, 200, 1, 3, 2});
    solution.longestConsecutive(arr);
    // your test code here
}

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */
