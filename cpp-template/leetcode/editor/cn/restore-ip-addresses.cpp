/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30201
 *
 * [93] 复原 IP 地址
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
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        vector<int> tmp;
        traverse(tmp, s, 0);
        return res;
    }
    void traverse(vector<int> &addr, const string &s, int start) {
        if (addr.size() > 4) return;
        if (addr.size() == 4 && start >= s.size() && addr[3] <= 255) {
            ostringstream oss;
            oss << addr[0] << '.' << addr[1] << '.' << addr[2] << '.'
                << addr[3];
            res.push_back(oss.str());
            return;
        }
        if (s[start] == '0') {
            addr.push_back(0);
            traverse(addr, s, start + 1);
            addr.pop_back();
            return;
        }
        for (int i = 1; i <= 3; i++) {
            int t = atoi(s.substr(start, i).c_str());
            if (t > 255 || i + start > s.size()) continue;
            addr.push_back(t);
            // 提前剪枝
            if (addr.size() == 4 && start + i != s.size())
                ;
            else
                traverse(addr, s, start + i);
            addr.pop_back();
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    auto tmp = solution.restoreIpAddresses("101023");
    for (auto t : tmp) cout << t;
    // your test code here
}

/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */
