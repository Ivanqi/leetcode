#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ret = 0;
            int len = nums.size();
            for (int i = 0; i < len; i++) {
                ret ^= nums[i];
            }
            return ret;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2,2,1};
    int ret = So.singleNumber(nums);
    cout << "结果: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {4,1,2,1,2};
    int ret = So.singleNumber(nums);
    cout << "结果: " << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}