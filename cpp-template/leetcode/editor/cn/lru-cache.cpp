/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30201
 *
 * [146] LRU 缓存
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class DoubleNode {
   public:
    int key;
    int val;
    DoubleNode* prev;
    DoubleNode* next;
    DoubleNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class DoubleList {
    DoubleNode* head;
    DoubleNode* tail;
    int _size;

   public:
    DoubleList() : _size(0), head(nullptr), tail(nullptr) {
        head = new DoubleNode(0, 0);
        tail = new DoubleNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int size() { return this->_size; }

    DoubleNode* add_front(int key, int val) {
        DoubleNode* p = new DoubleNode(key, val);
        add_front(p);
        return p;
    }

    DoubleNode* add_front(DoubleNode* p) {
        p->next = head->next;
        head->next->prev = p;
        head->next = p;
        p->prev = head;
        _size++;

        return p;
    }

    void move_front(DoubleNode* p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        _size--;

        add_front(p);
    }
    DoubleNode* last() { return tail->prev; }
    void remove_end() {
        DoubleNode* tmp = tail->prev;
        if (tmp == head) return;
        tail->prev = tmp->prev;
        tmp->prev->next = tail;
        // delete tmp;
        _size--;
    }
};

class LRUCache {
   public:
    DoubleList cache;
    int capacity;
    unordered_map<int, DoubleNode*> hash;
    LRUCache(int cap) { this->capacity = cap; }

    int get(int key) {
        if (hash.count(key)) {
            refresh(key);
            return hash[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (hash.count(key)) {
            hash[key]->val = value;
            refresh(key);
            return;
        }
        if (cache.size() == capacity) {
            remove_unused();
        }
        add_item(key, value);
    }
    void refresh(int key) {
        auto p = hash[key];
        cache.move_front(p);
    }
    void remove_unused() {
        auto p = cache.last();
        hash.erase(p->key);
        cache.remove_end();
    }
    void add_item(int key, int val) {
        auto p = cache.add_front(key, val);
        hash[key] = p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache c(3);
    c.put(1, 1);
    c.put(2, 2);
    c.put(3, 3);
    c.put(4, 4);
    cout << c.get(4) << endl;
    cout << c.get(3) << endl;
    cout << c.get(2) << endl;
    cout << c.get(1) << endl;
    c.put(5, 5);

    cout << c.get(1) << endl;
    cout << c.get(2) << endl;
    cout << c.get(3) << endl;
    cout << c.get(4) << endl;
    cout << c.get(5) << endl;
    // your test code here
}
