/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30201
 *
 * [155] 最小栈
 */

#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MinStack {
   private:
    vector<int> stack;
    int _min = INT_MIN;

   public:
    MinStack() {}

    void push(int val) {
        if (stack.size() == 0) _min = val;
        stack.push_back(val);
        _min = min(_min, val);
    }

    void pop() {
        int top = this->top();
        stack.pop_back();
        if (top == _min) {
            _min = INT_MAX;
            for (auto n : stack) _min = min(n, _min);
        }
    }

    int top() { return *stack.rbegin(); }

    int getMin() { return _min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
//
["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */
