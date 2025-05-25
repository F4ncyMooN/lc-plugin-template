/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30201
 *
 * [239] 滑动窗口最大值
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
    deque<int> q;
    int max() { return q.front(); }
    void push(int v) {
        while (q.size() > 0 && v > *q.rbegin()) {
            q.pop_back();
        }
        q.push_back(v);
    }
    void pop(int v) {
        if (q.size() > 0 && q.front() == v) q.pop_front();
    }
};

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        Queue queue;
        if (k > nums.size()) return {};
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];

            queue.push(t);
            if (i < k - 1) continue;
            res.push_back(queue.max());
            queue.pop(nums[i - k + 1]);
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
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
