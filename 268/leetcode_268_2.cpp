#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            unordered_set<int> set;
            int len = nums.size();
            for (int i = 0; i < len; i++) {
                set.insert(nums[i]);
            }

            int missing = -1;
            for (int i = 0; i <= len; i++) {
                if (!set.count(i)) {
                    missing = i;
                    break;
                }
            }

            return missing;
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
    test_case_1(So);
}

