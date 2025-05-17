/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=30201
 *
 * [220] 存在重复元素 III
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
    long size = 0;
    long getIdx(long u) { return u >= 0 ? u / size : ((u + 1) / size) - 1; }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        size = valueDiff + 1L;
        unordered_map<long, long> counts;
        int left = 0, right = 0;
        while (right < nums.size()) {
            long r = nums[right] * 1L;
            auto idx = getIdx(r);
            if (counts.count(idx)) return true;
            if (counts.count(idx - 1) && abs(r - counts[idx - 1]) <= valueDiff) return true;
            if (counts.count(idx + 1) && abs(r - counts[idx + 1]) <= valueDiff) return true;
            counts[idx] = r;

            while (right - left >= indexDiff) {
                counts.erase(getIdx(nums[left++]));
            }
            right++;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    solution.size = 3;
    cout << solution.getIdx(-3L);
    cout << solution.getIdx(6L);
    vector<int> tst({1, 5, 9, 1, 5, 9});
    solution.containsNearbyAlmostDuplicate(tst, 2, 3);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */
