#include <iostream>
#include <algorithm>
using namespace std;
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() / 2];
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {3,2,3};
    int ret = So.majorityElement(nums);
    cout << "ret: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {2,2,1,1,1,2,2};
    int ret = So.majorityElement(nums);
    cout << "ret: " << ret << endl;
}

int main() {
    Solution So;
    test_case_2(So);
    return 0;
}