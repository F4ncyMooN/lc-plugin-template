/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30201
 *
 * [232] 用栈实现队列
 */

#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyQueue {
   public:
    MyQueue() {}

    void push(int x) {
        // push to the tail of stack, O(n)
        deque<int> tmp;
        while (!stack.empty()) {
            tmp.push_front(stack.front());
            stack.pop_front();
        }
        stack.push_front(x);
        while (!tmp.empty()) {
            stack.push_front(tmp.front());
            tmp.pop_front();
        }
    }

    int pop() {
        int tmp = this->peek();
        stack.pop_front();
        return tmp;
    }

    int peek() { return stack.front(); }

    bool empty() { return stack.empty(); }

   private:
    deque<int> stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"]\n[[], [1], [2], [], [],
[]]\n
// @lcpr case=end

 */
