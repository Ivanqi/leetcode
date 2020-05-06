#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if (nums.size() == 1) return true;
            if (!nums[0]) return false;

            vector<int> dp(nums.size());
            dp[0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (dp[i - 1] >= nums.size() - 1) return true;
                if (i <= dp[i - 1]) dp[i] = max(dp[i - 1], i + nums[i]);
            }
            return false;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ret = So.canJump(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {3, 2, 1, 0, 4};
    bool ret = So.canJump(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_3(Solution So) {
    vector<int> nums = {2, 5, 0, 0};
    bool ret = So.canJump(nums);
    cout << "结果为: " << ret << endl;
}

void test_case_4(Solution So) {
    vector<int> nums = {2, 3, 1, 1, 4};
    bool ret = So.canJump(nums);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_4(So);
    return 0;
}