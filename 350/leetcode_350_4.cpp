#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/***
 * 利用哈希表查找元素
 *  1. 用map<int, int>存放元素和出现次数，存放其中一个数组
 *  2. 另外一个数组在map中查找键值，若查到到，则检验出现此时是否为0，不为0，则插入结果，且改变出现次数
 */
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() > nums2.size()) swap(nums1, nums2);    // 用元素少的数组元素查找
            map<int, int> a;

            for (int i = 0; i < nums2.size(); i++) {    // 初始化map
                // count 返回指定元素出现的次数
                if (!a.count(nums2[i])) {
                    a.insert(map<int, int>::value_type(nums2[i], 1));
                } else {
                    a[nums2[i]]++;
                }
            }

            vector<int> res;
            for (int i = 0; i < nums1.size(); i++) {
                if (a.count(nums1[i])) {
                    if (a[nums1[i]] != 0) {
                        res.push_back(nums1[i]);
                        a[nums1[i]]--;
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
    test_case_1(So);
    return 0;
}