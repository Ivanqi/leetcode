#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            int i = 0;
            int len = nums.size();

            int ret = 0;

            while (i < len) {
                if (nums[i] != i) {
                    return i;
                }
                i++;
            }

            return len;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {3,0,1};
    int ret = So.missingNumber(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {0,1};
    int ret = So.missingNumber(nums);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
}

