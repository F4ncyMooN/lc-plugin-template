/*
 * @lc app=leetcode.cn id=LCR 125 lang=cpp
 * @lcpr version=30202
 *
 * [LCR 125] 图书整理 II
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class CQueue {
   public:
    CQueue() { this->is_reverse = false; }

    void appendTail(int value) {
        if (is_reverse) reverse_cart();
        first.push_back(value);
    }

    int deleteHead() {
        if (!is_reverse) reverse_cart();
        // check if second is empty
        if (second.empty()) return -1;
        auto data = *second.rbegin();
        second.pop_back();
        return data;
    }

   private:
    vector<int> first, second;
    bool is_reverse;
    void reverse_cart() {
        if (is_reverse) {
            // second is full, move stack to first
            while (!second.empty()) {
                first.push_back(*second.rbegin());
                second.pop_back();
            }
        } else {
            while (!first.empty()) {
                second.push_back(*first.rbegin());
                first.pop_back();
            }
        }

        this->is_reverse = !this->is_reverse;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["BookQueue", "push", "push", "pop"]\n[[], [1], [2], []]\n
// @lcpr case=end

 */
