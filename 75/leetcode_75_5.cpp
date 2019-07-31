#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;

        for (int i = 0; nums.size(); i++) {
            if (nums[i] == 0) {
                red++;
            } else if (nums[i] == 1) {
                white++;
            } else {
                blue++;
            }
        }

         for(int i = 0; i < red; i++) {
            nums[i] = 0;
        }

        for(int i = red; i < red + white; i++) {
            nums[i] = 1;
        }

        for(int i = red + white; i < red + white + blue; i++) {
            nums[i] = 2;
        }

        for(int i=0;i<nums.size();i++) {
            cout<<nums[i]<<",";  
        } 
    }
};

int main() 
{
    std::vector<int>nums;

    Solution Solution;
    
    nums.push_bask(2);
    nums.push_bask(0);
    nums.push_bask(2);
    nums.push_bask(1);
    nums.push_bask(1);
    nums.push_bask(0);
    Solution.sortColors(nums);
    
    return 0;
}