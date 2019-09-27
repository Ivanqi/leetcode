#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ret;
            for (vector<int>::iterator it1 = nums1.begin(); it1 != nums1.end(); it1++) {
                for (vector<int>::iterator it2 = nums2.begin(); it2 != nums2.end(); it2++) {
                    if (*it1 == *it2) {
                        ret.push_back(*it1);
                        *it1 = -10086;
                        *it2 = -10085;
                    }
                }
            }
            return ret;
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
    nums2.push_back(2);

    vector<int> res = So.intersect(nums1, nums2);
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

    vector<int> res = So.intersect(nums1, nums2);
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