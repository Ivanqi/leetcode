#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 先将两个数组合并，两个有序数组的合并也是归并排序中的一部分。然后根据奇数，还是偶数，返回中位数
 * 
 * 时间复杂度：遍历全部数组 (m+n)(m+n)
 * 
 * 空间复杂度：开辟了一个数组，保存合并后的两个数组 O(m+n)O(m+n)
 * 
 */
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();

            vector<int> nums(m + n);

            if (m == 0) {
                if (n % 2 == 0) {
                    return (nums2[n / 2  - 1] + nums2[n / 2]) / 2.0;
                } else {
                    return nums2[n / 2];
                }
            }

            if (n == 0) {
                if (m % 2 == 0) {
                    return (nums1[m / 2  - 1] + nums1[m / 2]) / 2.0;
                } else {
                    return nums1[m / 2];
                }
            }

            int count = 0, i = 0, j = 0;

            while (count != (m + n)) {
                if (i == m) {
                    while (j != n) {
                        nums[count++] = nums2[j++];
                    }
                    break;
                }

                if (j == n) {
                    while (i != m) {
                        nums[count++] = nums1[i++];
                    }
                    break;
                }


                if (nums1[i] < nums2[j]) {
                    nums[count++] = nums1[i++];
                }  else {
                    nums[count++] = nums2[j++];
                }
            }

            if (count % 2 == 0) {
                return (nums[count / 2 - 1] + nums[count / 2]) / 2.0;
            } else {
                return nums[count / 2];
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

    test_case_2();

    return 0;

}