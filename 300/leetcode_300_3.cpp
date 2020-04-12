#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();

            if (len == 0) return 0;
            vector<int> tail; // tail 一个严格上升的数组(从小到大)
            
            // tail 初始化
            tail.push_back(nums[0]);
            int end = 0;    // end: tail 最后元素的下标

            for (int i = 1; i < len; i++) {
                if (tail[end] < nums[i]) {
                    tail.push_back(nums[i]);
                    end++;
                } else {
                    // 二分查找
                    int left = 0;
                    int right = end;

                    while (left < right) {
                        int mid = (left + right) >> 1;
                        if (tail[mid] < nums[i]) {
                            left = mid + 1;
                        } else {
                            right = mid;
                        }
                    }
                    tail[left] = nums[i];
                }
            }
            printTail(tail);
            return end + 1;
        }

        int printTail(vector<int> &tail) {
            for (int i = 0; i < tail.size(); i++) {
                cout << tail[i] << " ";
            }
            cout << endl;
        }

};

void test_case_1(Solution So) {
    vector<int> nums = {
        10, 9, 2, 5, 3, 7, 101, 18
    };

    int ret = So.lengthOfLIS(nums);

    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    vector<int> nums = {
       10, 9, 2, 5, 3, 4
    };
    int ret = So.lengthOfLIS(nums);

    cout << "结果为:" << ret << endl;
}

void test_case_3(Solution So) {
    vector<int> nums = { 
        1, 3, 6, 7, 9, 4, 10, 5, 6
    };
    int ret = So.lengthOfLIS(nums);
    cout << "结果为:" << ret << endl;
}

void test_case_4(Solution So) {
    vector<int> nums = { 
        10, 9, 2, 5, 3, 7, 101, 18, 4, 8, 6, 12
    };
    int ret = So.lengthOfLIS(nums);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_4(So);

    return 0;
}