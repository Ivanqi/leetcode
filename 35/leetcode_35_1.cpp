#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int len = nums.size();
            int low = 0;
            int high = len - 1;

            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return low;
        }
};

void test_case_1(Solution So) {
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 5;

    cout << "下标为：" << So.searchInsert(nums, target) << endl;
}

void test_case_2(Solution So) {
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 2;

    cout << "下标为：" << So.searchInsert(nums, target) << endl;
}

void test_case_3(Solution So) {
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 7;

    cout << "下标为：" << So.searchInsert(nums, target) << endl;
}

void test_case_4(Solution So) {
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 0;

    cout << "下标为：" << So.searchInsert(nums, target) << endl;
}

int main() {
    Solution So;
    test_case_4(So);
}

