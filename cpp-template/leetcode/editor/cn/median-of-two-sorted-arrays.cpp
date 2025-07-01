/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30201
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n)%2 == 0) {
            return (findKth(nums1, nums2, (m+n)/2)+findKth(nums1, nums2, (m+n)/2+1))/2;
        }
        return findKth(nums1, nums2, (m+n)/2+1);
    }
    double findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        // k starts from 1
        return findKth(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k);
    }
    double findKth(
        vector<int>& nums1, int i1, int j1,
        vector<int>& nums2, int i2, int j2, int k) {
        // array has no elements
        if (i1 > j1) return nums2[i2+k-1];
        if (i2 > j2) return nums1[i1+k-1];
        if (k == 1) return min(nums1[i1], nums2[i2]);
        // using merge-sort, compare top k/2 elements
        int mid = (k/2), len1 = j1-i1+1, len2 = j2-i2+1;
        int idx1 = i1+min(mid, len1)-1, idx2 = i2+min(mid, len2)-1;
        int a = nums1[idx1], b = nums2[idx2];
        if (a <= b) { // nums1's front elements could be eliminated
            return findKth(nums1, idx1+1, j1, nums2, i2, j2, k-(idx1-i1+1));
        } else {
            return findKth(nums1, i1, j1, nums2, idx2+1, j2, k-(idx2-i2+1));
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> a1 = {1,3};
    vector<int> a2 = {2};
    solution.findMedianSortedArrays(a1, a2);
}



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

