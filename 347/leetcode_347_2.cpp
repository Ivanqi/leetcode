#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;

/**
 * 小顶堆
 * 时间复杂度: O(nlogk)
 * 空间复杂度: O(n)
 */
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> counter;
            int numsSize = nums.size();

            for (int i = 0; i < numsSize; i++) {
                ++counter[nums[i]];
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > Q;
            unordered_map<int, int>::iterator iter;

            for (iter = counter.begin(); iter != counter.end(); iter++) {
                auto pair = make_pair(iter->second, iter->first);
                if (Q.size() == k) {
                    if (pair < Q.top()) continue;
                    Q.pop();
                }
                Q.push(move(pair));
            }

            vector<int> ret(Q.size());
            k = ret.size();
            while (!Q.empty()) {
                ret[--k] = Q.top().second;
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

void test_case_4(Solution So) {
    vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
    int k = 2;

    vector<int> ret = So.topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}

int main() {

    Solution So;
    test_case_4(So);

    return 0;
}