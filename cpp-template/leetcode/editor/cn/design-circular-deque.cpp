/*
 * @lc app=leetcode.cn id=641 lang=cpp
 * @lcpr version=30201
 *
 * [641] 设计循环双端队列
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyCircularDeque {
   public:
    MyCircularDeque(int k) : q(k, -1) {
        front = 0;
        end = 0;
        size = k;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = prev(front);
        q[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        q[end] = value;
        end = next(end);
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        q[front] = -1;
        front = next(front);
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        end = prev(end);
        q[end] = -1;
        return true;
    }

    int getFront() { return q[front]; }

    int getRear() { return q[prev(end)]; }

    bool isEmpty() { return front == end && q[front] == -1; }

    bool isFull() { return front == end && q[front] != -1; }

   private:
    vector<int> q;
    int front, end, size;
    int next(int idx) { return (idx + 1) % size; }
    int prev(int idx) { return (size + idx - 1) % size; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

int main() {
    MyCircularDeque solution(3);
    solution.insertLast(3);
    solution.insertLast(2);
    solution.insertFront(3);
    solution.insertFront(4);
    solution.getRear();
    // your test code here
}
