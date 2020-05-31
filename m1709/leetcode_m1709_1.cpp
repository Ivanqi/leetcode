#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Solution {
    public:
        int getKthMagicNumber(int k) {

            long answer = 1;
            priority_queue<long, vector<long>, greater<long> > Q;
            set<long> S;

            Q.push(answer);
            S.insert(answer);
            vector<int> mask({3, 5, 7});


            for (int i = 1; i <= k; i++) {
                for (auto x: mask) {
                    if (S.count(x * answer) == 0) {
                        Q.push(x * answer);
                        S.insert(x * answer);
                    }
                }

                answer = Q.top();
                Q.pop();
            }

            return answer;
        }
};

void test_case_1(Solution So) {
    int k = 5;
    int ret = So.getKthMagicNumber(k);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}