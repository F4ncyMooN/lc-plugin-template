/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 * @lcpr version=30201
 *
 * [1670] 设计前中后队列
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class FrontMiddleBackQueue {
    // 用两个列表表示队列的左右两部分，一遍从中间操作元素
    deque<int> left;
    deque<int> right;
    // 如果是奇数个元素，维护左边少右边多，所以：
    // 1、如果有偶数个元素时，pushMiddle 优先向右边添加
    // 2、如果有奇数个元素时，popMiddle 优先从右边删除
    // 3、如果只有 1 个元素，popFront 的时候，要去右边删除
    // 要把以上三个特点写到代码里，才能保证细节不出错

    // 维护左边少右边多的状态，每次增删元素之后都要执行一次
    void balance() {
        // 右边最多比左边多一个元素
        if (right.size() > left.size() + 1) {
            // 右边多，匀一个给左边
            left.push_back(right.front());
            right.pop_front();
        }
        if (left.size() > right.size()) {
            // 左边多，匀一个给右边
            right.push_front(left.back());
            left.pop_back();
        }
    }

   public:
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (size() % 2 == 0) {
            // 如果有偶数个元素时，pushMiddle 优先向右边添加
            right.push_front(val);
        } else {
            left.push_back(val);
        }
        balance();
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (size() == 0) {
            return -1;
        }
        if (size() == 1) {
            // 如果只有 1 个元素，popFront 的时候，要去右边删除
            int e = right.front();
            right.pop_front();
            return e;
        }
        int e = left.front();
        left.pop_front();
        balance();
        return e;
    }

    int popMiddle() {
        if (size() == 0) {
            return -1;
        }
        int e;
        if (size() % 2 == 0) {
            e = left.back();
            left.pop_back();
        } else {
            // 如果有奇数个元素时，popMiddle 优先从右边删除
            e = right.front();
            right.pop_front();
        }
        balance();
        return e;
    }

    int popBack() {
        if (size() == 0) {
            return -1;
        }
        int e = right.back();
        right.pop_back();
        balance();
        return e;
    }

    int size() { return left.size() + right.size(); }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle",
"popMiddle",\n"popBack", "popFront"]\n[[], [1], [2], [3], [4], [], [], [], [], []]\n
// @lcpr case=end

 */
