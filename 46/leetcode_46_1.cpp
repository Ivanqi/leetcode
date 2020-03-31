#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> ret;
        vector<vector<int>> permute(vector<int>& nums) {
            if (nums.size() <= 0 ) return ret;
            
            perm(nums, 0, nums.size() - 1);
            
            return ret;
        }

        // 路径：记录在nums中
        // 选择列表: 
        // 结束条件：nums中查找到数量满足m
        void perm(vector<int>& nums, int k, int m) {
            
            if (k == m) {
                // for (int i = 0; i <= m; ++i) {
                //     cout << nums[i] << " ";
                // }
                // cout << endl;
                ret.push_back(nums);
            } else {
                for (int i = k; i <= m; i++) {
                    // 做选择
                    swap(nums[i], nums[k]);
                    // 进入下一层决策树
                    perm(nums, k + 1, m);
                    // 取消选择
                    swap(nums[i], nums[k]);
                }
            }
        }
        
        void swap(int &a, int &b) {
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
};


void test_case_1(Solution So) {

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int>> ret = So.permute(nums);

    cout << "[ \n";
    for (int i = 0; i < ret.size(); i++) {
        vector<int> retn = ret[i];
        cout << "\t[ ";
        for (int j = 0; j < retn.size(); j++) {
            cout << retn[j] << " ";
        }
        cout << "]\n";
    }
     cout << "\n]";
}

int main () {

    Solution So;

    test_case_1(So);
    return 0;
}