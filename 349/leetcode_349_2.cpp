#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() > nums2.size()) {
                swap(nums1, nums2);
            }
            vector<int> res;
            for (int i = 0; i < nums1.size(); i++) {
                if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
                    if (find(res.begin(), res.end(), nums1[i]) == res.end()) {
                        res.push_back(nums1[i]);
                    }
                }
            }
            return res;
        }
};

void test_case_1(Solution So) {
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);
    vector<int> nums2;
    nums2.push_back(2);

    vector<int> res = So.intersection(nums1, nums2);
    cout << "val: [";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
    cout << "] " << endl;
}

void test_case_2(Solution So) {
    vector<int> nums1;
    nums1.push_back(4);
    nums1.push_back(9);
    nums1.push_back(5);
    vector<int> nums2;
    nums2.push_back(9);
    nums2.push_back(4);
    nums2.push_back(9);
    nums2.push_back(8);
    nums2.push_back(4);

    vector<int> res = So.intersection(nums1, nums2);
    cout << "val: [";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ",";
    }
    cout << "] " << endl;
}

int main() {
    Solution So;
    test_case_2(So);
    return 0;
}