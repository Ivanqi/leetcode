#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 不需要将两个数组真的合并，只需要找到中位数在哪里就可以了
 * 
 * 时间复杂度：遍历 len/2+1 次，len=m+n，所以时间复杂度依旧是 O(m+n)
 * 
 * 空间复杂度是 O(1）O(1）
 * 
 */
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            int len = m + n;

            int left = -1, right = -1;
            int nums1Start = 0, nums2Start = 0;

            for (int i = 0; i <= len / 2; i++) {
                left = right;
                if (nums1Start < m && (nums2Start >= n || nums1[nums1Start] < nums2[nums2Start])) {
                    right = nums1[nums1Start++];
                } else {
                    right = nums2[nums2Start++];
                }
            }

            if ((len & 1) == 0) {
                return (left + right) / 2.0;
            } else {
                return right;
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