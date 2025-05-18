/*
 * @lc app=leetcode.cn id=933 lang=cpp
 * @lcpr version=30201
 *
 * [933] 最近的请求次数
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class RecentCounter {
   public:
    RecentCounter() {}

    int ping(int t) {
        requests.push(t);
        int top = requests.front();
        while (t - top > 3000) {
            requests.pop();
            top = requests.front();
        }

        return requests.size();
    }

   private:
    queue<int> requests;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping", "ping"]\n[[], [1], [100], [3001], [3002]]\n
// @lcpr case=end

 */
