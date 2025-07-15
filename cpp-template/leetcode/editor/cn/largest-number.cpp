/*
 * @lc app=leetcode.cn id=179 lang=cpp
 * @lcpr version=30201
 *
 * [179] 最大数
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    string largestNumber(vector<int> &nums) {
        vector<string> res;
        for (auto n : nums) {
            res.push_back(to_string(n));
        }
        sort(res.begin(), res.end(),
             [](const string &a, const string &b) { return a + b > b + a; });
        ostringstream iss;
        for (auto &s : res) {
            iss << s;
        }
        string ans = iss.str();
        if (ans[0] == '0') return "0";
        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> tmp = {111311, 1113};
    cout << solution.largestNumber(tmp);
    // your test code here
}

/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

 */
