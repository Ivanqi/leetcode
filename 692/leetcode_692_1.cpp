#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    private:
        struct cmp {
            bool operator()(pair<int, string> &a, pair<int, string> &b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second < b.second;
            }
        };
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            unordered_map<string, int> counter;
            priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> minHeap;
            
            for (auto v: words) {
                counter[v]++;
            }
            
            for (auto x: counter) {
                minHeap.push(move(make_pair(x.second, x.first)));
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }

            vector<string> res(k);
            for (int i = k - 1; i >= 0; --i) {
                res[i] = minHeap.top().second;
                minHeap.pop();
            }
            return res;
        }
};

void test_case_1(Solution So) {
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    int k = 2;

    vector<string> ret = So.topKFrequent(words, k);

    for (auto v: ret) {
        cout << v << endl;
    }
}

void test_case_2(Solution So) {
    vector<string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    int k = 4;

    vector<string> ret = So.topKFrequent(words, k);

    for (auto v: ret) {
        cout << v << endl;
    }
}

void test_case_3(Solution So) {
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    int k = 1;

    vector<string> ret = So.topKFrequent(words, k);

    for (auto v: ret) {
        cout << v << endl;
    }
}

int main() {
    Solution So;
    test_case_3(So);
    return 0;
}