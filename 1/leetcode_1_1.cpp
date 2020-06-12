#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int len = nums.size();
            int i = 0;
            int j = i + 1;

            while (i < len) {
                if (j >= len) {
                    i++;
                    j = i + 1;
                }
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
                j++;
            }
            return {};
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ret = So.twoSum(nums, target);
    for (auto x: ret) {
        cout << x << endl;
    }
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}
