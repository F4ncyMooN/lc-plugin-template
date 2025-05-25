/*
 * @lc app=leetcode.cn id=853 lang=cpp
 * @lcpr version=30201
 *
 * [853] 车队
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> sorted;
        for (int i = 0; i < position.size(); i++) {
            sorted.insert(make_pair(position[i], speed[i]));
        }
        stack<double> stk;
        for (auto& [p, s] : sorted) {
            double remain_time = (target - p) / (s + 0.0);
            while (stk.size() > 0 && stk.top() <= remain_time) {
                stk.pop();
            }
            stk.push(remain_time);
        }
        return stk.size();
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 12\n[10,8,0,5,3]\n[2,4,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[3]\n[3]\n
// @lcpr case=end

// @lcpr case=start
// 100\n[0,2,4]\n[4,2,1]\n
// @lcpr case=end

 */
