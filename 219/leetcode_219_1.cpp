#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> map;

            for (int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                if (map.count(nums[i]) && i - map[num] <= k) {
                    return true;
                }
                map[num] = i;

            }
            return false;
        }
};