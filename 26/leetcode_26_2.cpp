#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        /**
         * 快慢指针。快指针判断上下两个值是否相等，慢指针记录不相等的个数
         * 
         */
        int removeDuplicates(vector<int>& nums) {
            int len = nums.size();
            if (len <= 0) return 0;

            int fastIdx = 1;
            int slowIdx = 1;

            while (fastIdx < len) {
                if (nums[fastIdx] != nums[fastIdx - 1]) {
                    nums[slowIdx] = nums[fastIdx];
                    slowIdx++;
                }
                fastIdx++;
            }
            
            return slowIdx;
        }
};

void test_case_1(Solution So) {
    vector<int> nums {1,1,2};
    int ret = So.removeDuplicates(nums);
    
    for (int i = 0; i < ret; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

void test_case_2(Solution So) {
    vector<int> nums {0,0,1,1,1,2,2,3,3,4};
    int ret = So.removeDuplicates(nums);
    
    for (int i = 0; i < ret; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}