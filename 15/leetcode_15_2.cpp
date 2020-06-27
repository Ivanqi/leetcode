#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> ret;
            
            sort(nums.begin(), nums.end());
            
            // 枚举 a
            for (int first = 0; first < n; ++first) {
                // 需要和上一次枚举的数不同
                if (first > 0 && nums[first] == nums[first - 1]) {
                    continue;
                }

                // c 对应的指针初始指向数组的最右端
                int third = n - 1;
                int target = -nums[first];
                // 枚举b
                for (int second = first + 1; second < n; ++second) {
                    // 需要和上一次枚举的数不同
                    if (second > first + 1 && nums[second] == nums[second - 1]) {
                        continue;
                    }

                    // 需要保证b的指针在c的指针的左侧
                    while (second < third && nums[second] + nums[third] > target) {
                        --third;
                    }

                    // 如果指针重合，随着b后续的增加
                    // 就不会有满足 a + b + c = 0 并且 b < c的c了，可以退出循环
                    if (second == third) {
                        break;
                    }

                    if (nums[second] + nums[third] == target) {
                        ret.push_back({nums[first], nums[second], nums[third]});
                    }
                }
            }
            return ret;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ret = So.threeSum(nums);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}