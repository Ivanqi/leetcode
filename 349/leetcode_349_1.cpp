#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            set<int> n1(nums1.begin(), nums2.end());
            vector<int> res;

            for (int i = 0; i < nums2.size(); i++) {
                if (n1.find(nums2[i]) != n1.end()) {
                    if (find(res.begin(), res.end(), nums2[i]) == res.end()) {
                        res.push_back(nums2[i]);
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