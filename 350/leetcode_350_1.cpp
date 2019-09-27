#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            for (int i = 0; i < nums1.size(); i++) {
                if (nums2.size() < 0) break;
                for (int j = 0; j < nums2.size(); j++) {
                    if (nums1[i] == nums2[j]) {
                        res.push_back(nums1[i]);
                        nums1.erase(nums1.begin() + i);
                        nums2.erase(nums2.begin() + j);
                        // 每次删除一个元素后，都会跳过下一个元素。因此在erase掉一个元素后，应该要--才行
                        i--;
                        j--;
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