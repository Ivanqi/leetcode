#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            int len = T.size();
            stack<int> S; 
            vector<int> ret(len);
            for (int i = 0; i < len; i++) {
                while (!S.empty() && T[i] > T[S.top()]) {
                    auto t = S.top(); S.pop();
                    ret[t] = i - t;
                }
                S.push(i);
            }

            return ret;
        }
};

void test_case_1(Solution So) {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ret = So.dailyTemperatures(T);

    for (auto x: ret) {
        cout << x << endl;
    }
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}