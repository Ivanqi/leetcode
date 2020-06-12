#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> m;
            int len = nums.size();

            for (int i = 0; i < len; i++) {
                m[nums[i]] = i;
            }

            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                if (m.find(complement) != m.end() && m[complement] != i) {
                    return {i, m[complement]};
                }
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
