/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30202
 *
 * [207] 课程表
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
   public:
    vector<bool> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(prerequisites.size(), false);
        unordered_map<int, vector<int>> dag;
        for (const auto link : prerequisites) {
            if (!dag.count(link[1])) dag[link[1]] = vector<int>();
            dag[link[1]].push_back(link[0]);
        }
        for (const auto link : dag) {
            if (find_loop(dag, link.first)) return false;
        }
        return true;
    }
    bool find_loop(unordered_map<int, vector<int>>& dag, int root) {
        if (visited[root]) return false;
        // dfs loop
        vector<int> path;
        path.push_back(root);
        return dfs(path, dag);
    }
    bool dfs(vector<int>& path, unordered_map<int, vector<int>>& dag) {
        auto last = *path.rbegin();
        if (!dag.count(last)) return false;
        if (visited[last]) return false;
        for (auto next : dag[last]) {
            // check if on the path
            for (auto p : path) {
                if (p == next) return true;
            }
            path.push_back(next);
            if (dfs(path, dag)) return true;
            path.pop_back();
            visited[next] = true;
        }
        visited[last] = true;
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> edges({{0, 1}, {3, 1}, {1, 3}, {3, 2}});
    cout << solution.canFinish(4, edges) << endl;
    // your test code here
}

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */
