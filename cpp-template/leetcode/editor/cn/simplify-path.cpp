/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30201
 *
 * [71] 简化路径
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    string simplifyPath(string path) {
        deque<string> folders;
        string tmp;
        for (char c : path) {
            if (c != '/') {
                tmp.push_back(c);
                continue;
            }
            if (tmp == "") {
            } else if (tmp == ".") {
            } else if (tmp == "..") {
                if (folders.size() > 0) folders.pop_back();
            } else {
                folders.push_back(tmp);
            }
            tmp = "";
        }
        if (tmp == "..") {
            if (folders.size() > 0) {
                folders.pop_back();
            }
        } else if (tmp != "" && tmp != ".") {
            folders.push_back(tmp);
        }
        tmp = "";
        while (folders.size() > 0) {
            tmp += '/' + *folders.begin();
            folders.pop_front();
        }
        return tmp == "" ? "/" : tmp;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.simplifyPath("/../");
    // your test code here
}

/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */
