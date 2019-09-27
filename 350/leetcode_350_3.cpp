#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 具有记忆的双指针法
 *  1. 先将两数组排序
 *  2. 一旦找到相同的元素，下一次查找位置不需要从头开始，直接从下一个位置查找
 *  3. 若未找到，此时nums1[i] > nums2[nums2.size() - 1] 大说明后面都没有相同的元素，反之从上一次搜索的位置的下一个开始查找
 */
class Solution {
    public:
        static bool cmp(const int &a, const int &b) {
            return a < b;
        }
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
           if (nums1.empty() || nums2.empty()) return {};

           sort(nums1.begin(), nums1.end(), cmp);
           sort(nums2.begin(), nums2.end(), cmp);

           if (nums1[0] > nums2[nums2.size() - 1]) return {};

           vector<int> res;
           int i = 0;   // 指向nums1 的指针
           int k = 0;   // 指向nums2 的指针
           int j = 0;   // 记忆上一次搜索位置

            for (; i < nums1.size(); i++) {
                while (k < nums2.size() && nums1[i] != nums2[k]) {   // 找到相同元素的nums2的下标
                    k++;
                }

                if (k != nums2.size()) {
                    res.push_back(nums2[k]);
                    k++;
                    j = k;  // 记忆
                } else if (nums1[i] > nums2[k - 1]) {   // 由于排序过，所以可以这样判断
                    break;
                } else {
                    k = j;
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