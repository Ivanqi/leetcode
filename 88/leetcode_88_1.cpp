#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int a = 0, b = 0;

            vector<int> arr;
            int cur;
            int sort[m + n];
            while (a < m || b < n) {
                if (a == m) { 
                    cur = nums2[b++];
                } else if (b == n) {
                    cur = nums1[a++] ;
                } else if (nums1[a] < nums2[b]) {
                    cur = nums1[a++];
                } else {
                    cur = nums2[b++];
                }
                sort[a + b - 1] = cur; 
            }

            for (int i = 0; i != m + n; ++i) {
                nums1[i] = sort[i];
            }
        }
};

void test_case_1(Solution So) {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    So.merge(nums1, m, nums2, n);
    for (auto a: nums1) {
        cout << a << " ";
    }
}

void test_case_2(Solution So) {
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    int m = 1;
    int n = 0;

    So.merge(nums1, m, nums2, n);
    for (auto a: nums1) {
        cout << a << " ";
    }
}

void test_case_3(Solution So) {
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    int m = 0;
    int n = 1;

    So.merge(nums1, m, nums2, n);
    for (auto a: nums1) {
        cout << a << " ";
    }
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}