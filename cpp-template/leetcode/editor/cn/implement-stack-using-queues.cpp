/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30201
 *
 * [225] 用队列实现栈
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyStack {
   public:
    queue<int> q;
    int top_ele;
    MyStack() {}

    void push(int x) {
        top_ele = x;
        q.push(x);
    }

    int pop() {
        if (q.size() == 1) {
            q.pop();
        } else {
            for (int i = 0; i < q.size() - 2; i++) {
                q.push(q.front());
                q.pop();
            }
            top_ele = q.front();
            q.push(q.front());
            q.pop();

            int tmp = q.front();
            q.pop();
            return tmp;
        }

        return top_ele;
    }

    int top() { return top_ele; }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"]\n[[], [1], [2], [], [], []]\n
// @lcpr case=end

 */
