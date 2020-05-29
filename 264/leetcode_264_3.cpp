#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
    public:
        int nthUglyNumber(int n) {
            priority_queue<double, vector<double>, greater<double> > Q;
            set<double> s;
            double answer = 1;
            s.insert(answer);
            vector<int> mask({2, 3, 5});

            for (int i = 1; i < n; ++i) {

                for (int &j: mask) {
                    if (s.count(answer * j) == 0) {
                        Q.push(answer * j);
                        s.insert(answer * j);
                    }
                }
                answer = Q.top();
                Q.pop();
            }
            
            return answer;
        }
};

void test_case_1(Solution So) {
    int n = 10;
    int ret = So.nthUglyNumber(n);
    cout << "结果为: " << ret <<endl;
}

void test_case_2(Solution So) {
    int n = 1407;
    int ret = So.nthUglyNumber(n);
    cout << "结果为: " << ret <<endl;
}


int main() {

    Solution So;
    test_case_2(So);
    return 0;
}