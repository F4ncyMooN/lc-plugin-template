/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 * @lcpr version=30201
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Queue {
   public:
    deque<int> _min, _max;
    void push(int v) {
        while (_max.size() > 0 && v > *_max.rbegin()) {
            _max.pop_back();
        }
        _max.push_back(v);

        while (_min.size() > 0 && v < *_min.rbegin()) {
            _min.pop_back();
        }
        _min.push_back(v);
    }
    int max() { return _max.front(); }
    int min() { return _min.front(); }

    void pop(int v) {
        if (_max.size() > 0 && _max.front() == v) _max.pop_front();
        if (_min.size() > 0 && _min.front() == v) _min.pop_front();
    }
};
class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        Queue q;
        int longest_size = 0;
        for (int right = 0, left = 0; right < nums.size(); right++) {
            q.push(nums[right]);
            for (; q.max() - q.min() > limit; left++) {
                q.pop(nums[left]);
            }
            longest_size = max(longest_size, right - left + 1);
        }
        return longest_size;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [8,2,4,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [10,1,2,4,7,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,2,4,4,2,2]\n0\n
// @lcpr case=end

 */
