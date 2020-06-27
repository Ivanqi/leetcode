#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 超时
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int len = nums.size();
            vector<vector<int>> ret;
            unordered_map<string, int> m;
            
            sort(nums.begin(), nums.end());
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    for (int k = j + 1; k < len; k++) {
                        if ((nums[i] + nums[j] + nums[k]) == 0) {
                            string key = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
                            if (m.find(key) != m.end()) {
                                continue;
                            } else {
                                ret.push_back({nums[i], nums[j], nums[k]});
                                 m[key] = 1;
                            }
                        }
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