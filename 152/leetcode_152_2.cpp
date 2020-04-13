#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int maxNums = INT_MIN, imax = 1, imin = 1;
            int len = nums.size();

            for (int i = 0; i < len; i++) {
                if (nums[i] < 0) {
                    int tmp = imax;
                    imax = imin;
                    imin = tmp;
                }
                cout << "nums[i]: " << nums[i] << " | imax:" << imax << " | imin:" << imin << " | maxNums:" << maxNums << endl;
                imax = max(imax * nums[i], nums[i]);
                imin = min(imin * nums[i], nums[i]);

                maxNums = max(maxNums, imax);
            }

            return maxNums;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 3, -2, 4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {-2, 3, -4};
    int ret = So.maxProduct(nums);
    cout << "结果为: " << ret << endl;
}

int main() {
    Solution So;

    test_case_2(So);
}