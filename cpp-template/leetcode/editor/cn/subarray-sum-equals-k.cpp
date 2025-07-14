/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30201
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {
        int _sum = 0, n = nums.size();
        int res = 0, sj = 0;
        // s[j]-s[i] = k ==> s[j]-k = s[i], 存一下s[i] 出现的次数
        unordered_map<int, int> count;
        count[0] = 1;
        for (int j = 1; j <= nums.size(); j++) {
            sj = sj + nums[j - 1];
            if (count.count(sj - k)) res += count[sj - k];
            count[sj]++;
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
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */
