#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

/**
 * 大顶堆
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(n)
 */
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> counter;
            vector<int> ret;
            int numsSize = nums.size();

            for (int i = 0; i < numsSize; i++) {
                counter[nums[i]]++;
            }
            int n = counter.size();

            priority_queue<pair<int, int> > Q;
            unordered_map<int, int>::iterator iter;
            for (iter = counter.begin(); iter != counter.end(); iter++) {
                Q.push(make_pair(iter->second, iter->first));
            }

            for (int i = 0; i < k; i++) {
                pair<int, int> top = Q.top();
                ret.push_back(top.second);
                Q.pop();
            }
            return ret;
        }
};

void test_case_1(Solution So) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ret = So.topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}

void test_case_2(Solution So) {
    vector<int> nums = {1};
    int k = 1;

    vector<int> ret = So.topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}

void test_case_3(Solution So) {
    vector<int> nums = {-1, -1};
    int k = 1;

    vector<int> ret = So.topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}

int main() {

    Solution So;
    cout << "case 1" << endl;
    test_case_1(So);
    cout << endl;
    
    cout << "case 2" << endl;
    test_case_2(So);
    cout << endl;

    cout << "case 3" << endl;
    test_case_3(So);
    cout << endl;
    return 0;
}