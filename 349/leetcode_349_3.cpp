#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            // 用unordered_set 对 nums1的元素去重
            unordered_set<int> s1;
            for (auto& e : nums1) {
                s1.insert(e);
            }
            
            // 用unordered_set 对 nums2 的元素去重
            unordered_set<int> s2;
            for (auto& e : nums2) {
                s2.insert(e);
            }

            vector<int> v;
            //遍历s1，如果s1中的某个元素在s2中出现，即为二者交集
            for (auto& e : s1) {
                if (s2.find(e) != s2.end()) {
                    v.push_back(e);
                }
            }
            return v;
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
    test_case_1(So);
    return 0;
}