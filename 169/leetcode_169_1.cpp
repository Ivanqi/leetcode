#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int> mymap;
            int len = nums.size();
            int maxLimit = len / 2;

            for (int i = 0; i < len; i++) {
                mymap[nums[i]] ++;
                if (mymap[nums[i]] > maxLimit ) return nums[i];
            }

            return -1;
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