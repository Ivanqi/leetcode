#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


class Solution {
    public:
        int nthSuperUglyNumber(int n, vector<int>& primes) {
            priority_queue<long long, vector<long long>, greater<long long> >  Q;
            long long answer = 1;
            Q.push(answer);
            unordered_set<long long> S;
            S.insert(answer);

            for (int i = 1; i <= n; ++i) {
                for (long long x: primes) {
                    long long next = answer * x;
                    if (next <= INT32_MAX && S.count(next) == 0) {
                        Q.push(next);
                        S.insert(next);
                    }
                }
                answer = Q.top();
                Q.pop();
            }
            return answer;
        }
};

void test_case_1(Solution So) {
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};

    int ret = So.nthSuperUglyNumber(n, primes);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int n = 100000;
    vector<int> primes = {2, 7, 13, 19};

    int ret = So.nthSuperUglyNumber(n, primes);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}