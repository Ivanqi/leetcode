#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if (nums.empty()) return -1;
            int left = 0;
            int right = nums.size() - 1;
            while (left <= right) {
                int mid = left + ((right - left)>>1);
                if (nums[mid] == target) {
                    return mid;
                }
                //mid位于右半部分
                if (nums[mid] < nums[right]) {
                    //target <= nums[right],说明target位于右半部分
                    //nums[mid] < target,说明target位于右半部分的右半部分,left = mid + 1
                    if (target <= nums[right] && nums[mid] < target) {
                        left = mid + 1;
                    }
                    //target > nums[right],说明target位于左半部分,right = mid - 1
                    //target < nums[mid],说明target位于右半部分的左半部分,right = mid - 1
                    else {
                        right = mid - 1;
                    }
                }
                //mid位于左半部分
                else if (nums[mid] >= nums[right]) {
                    //nums[left] <= target,说明target位于左半部分
                    //target < nums[mid],说明target位于左半部分的左半部分,right = mid - 1
                    if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1;
                    }
                    //nums[left] > target,说明target位于右半部分,left = mid + 1
                    //target > nums[mid],说明target位于左半部分的右半部分,left = mid + 1
                    else {
                        left = mid + 1;
                    }
                }
            }
            return -1;
        }
};

int main() {

    Solution So;
    // int t1[] = {7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
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