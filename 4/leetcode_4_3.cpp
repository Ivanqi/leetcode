#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            int m = nums2.size();

            int left = (n + m + 1) / 2;
            int right = (n + m + 2) / 2;

            // 将偶数和奇数的情况合并，如果是奇数，会求两次同样的k
            return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) +
                getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
        }

        int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
            int len1 = end1 - start1 + 1;
            int len2 = end2 - start2 + 1;

            // 让len1 的长度小于 len2，这样就能保证如果有数组空了，一定是len1
            if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
            if (len1 == 0) return nums2[start2 + k - 1];

            if (k == 1) return min(nums1[start1], nums2[start2]);

            int i = start1 + min(len1, k / 2) - 1;
            int j = start2 + min(len2, k / 2) - 1;

            if (nums1[i] > nums2[j]) {
                return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
            } else {
                return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
            }

        }

};

void test_case_1 () {
    vector<int> nums1 {1, 3};
    vector<int> nums2 {2};

    Solution so;
    
    std::cout << so.findMedianSortedArrays(nums1, nums2) << std::endl;

}

void test_case_2 () {
    vector<int> nums1 {1, 2};
    vector<int> nums2 {3, 4};

    Solution so;
    
    std::cout << so.findMedianSortedArrays(nums1, nums2) << std::endl;

}

int main () {

    test_case_1();

    return 0;

}