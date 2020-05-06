#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 */
class Solution {
    public:
        int jump(vector<int>& nums) {
            int maxPos = 0, end = 0, n = nums.size(), step = 0;
            for (int i = 0; i < n - 1; i++) {
                if (maxPos >= i) {
                    maxPos = max(maxPos, i + nums[i]);
                    if (i == end) {
                        ++step;
                        end = maxPos;
                    }
                }
            }
            return step;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {2, 3, 1, 1, 4};
    int ret = So.jump(nums);
    cout << "结果为: " << ret << endl;
}

int main() {1

    Solution So;
    test_case_1(So);
    return 0;
}