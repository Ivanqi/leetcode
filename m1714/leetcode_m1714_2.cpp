#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
    public:
        vector<int> smallestK(vector<int>& arr, int k) {
            priority_queue<int> Q;

            int len = arr.size();
            for (int i = 0; i < len; i++) {
                Q.push(arr[i]);
                if (Q.size() > k) {
                    Q.pop();
                }
            }
            int QSize = Q.size();
            vector<int> ret(QSize);
            while (!Q.empty()) {
                k--;
                ret[k] = Q.top();
                Q.pop();
            }
            return ret;
        }
};

void test_case_1(Solution So) {
   vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
   int k = 4;
   vector<int> ret = So.smallestK(arr, k); 
    for (auto x: ret) {
       cout << x << " ";
    }
    cout << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}
