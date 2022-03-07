#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        /**
         * @brief 移除指针
         * 通过一个指针标记，不与val相等的位置
         * 
         */
        int removeElement(vector<int>& nums, int val) {
            int len = nums.size();
            if (len <= 0) return 0;

            int idx = 0;

            for (int i = 0; i < len; i++) {
                if (nums[i] != val) {
                    nums[idx] = nums[i];
                    idx++;
                }
            }

            return idx;
        }
};

void test_case_1(Solution So) {
    vector<int> nums {3,2,2,3};
    int val = 3;
    int ret = So.removeElement(nums, val);
    
    for (int i = 0; i < ret; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

void test_case_2(Solution So) {
    vector<int> nums {0,0,1,1,1,2,2,3,3,4};
    int val = 2;
    int ret = So.removeElement(nums, val);
    
    for (int i = 0; i < ret; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}