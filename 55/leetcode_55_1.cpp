#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 失败例子
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int farthest = 0;

            for (int i = 0; i <= n; i++) {
                int tmp = nums[farthest];
                farthest += tmp;
                if (tmp <= 0) break;
                i += tmp;
            }
            return farthest >= n - 1;
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

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}