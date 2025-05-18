/*
 * @lc app=leetcode.cn id=622 lang=cpp
 * @lcpr version=30201
 *
 * [622] 设计循环队列
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyCircularQueue {
   public:
    MyCircularQueue(int k) : q(k, -1) {
        front = 0;
        end = 0;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        q[end] = value;
        end = (end + 1) % size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        q[front] = -1;
        front = (front + 1) % size;
        return true;
    }

    int Front() { return q[front]; }

    int Rear() { return q[(end + size - 1) % size]; }

    bool isEmpty() { return front == end && q[front] == -1; }

    bool isFull() { return front == end && q[front] != -1; }

   private:
    vector<int> q;
    int front, end, size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}
