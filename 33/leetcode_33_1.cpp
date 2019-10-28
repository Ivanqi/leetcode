#include <iostream>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int lo = 0, hi = nums.size() - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                    lo = mid + 1;
                else
                    hi = mid;
            }
            return lo == hi && nums[lo] == target ? lo : -1;
        }
};

int main() {

    Solution So;
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);

    int i;
    int index = -1;
    for (i = -1; i < 11; i++) {
        index = So.search(nums, i);
        cout << "Find " << i << " at index " << index << endl;
    }
}