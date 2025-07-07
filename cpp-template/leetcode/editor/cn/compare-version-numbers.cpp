/*
 * @lc app=leetcode.cn id=165 lang=cpp
 * @lcpr version=30201
 *
 * [165] 比较版本号
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
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1), v2 = split(version2);
        int size = max(v1.size(), v2.size());
        for (int i = 0; i < size; i++) {
            if (i >= v1.size()) return -1;
            if (i >= v2.size()) return 1;

            if (v1[i] < v2[i]) return -1;
            if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
    vector<int> split(string version) {
        vector<int> res;
        int i = 0;
        // split by '.'
        for (int j = 1; j <= version.size(); j++) {
            if (i <= j && (j == version.size() || version[j] == '.')) {
                res.push_back(atoi(version.substr(i, j - i + 1).c_str()));
                i = j + 1;
            }
        }

        // rm tailing zero
        for (int i = res.size() - 1; i > 0; i--) {
            if (res[i] != 0) break;
            res.pop_back();
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.compareVersion("1.01.0", "1.1");
    // your test code here
}

/*
// @lcpr case=start
// "1.2"\n"1.10"\n
// @lcpr case=end

// @lcpr case=start
// "1.01"\n"1.001"\n
// @lcpr case=end

// @lcpr case=start
// "1.0"\n"1.0.0.0"\n
// @lcpr case=end

 */
