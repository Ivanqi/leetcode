#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        int nthUglyNumber(int n) {
            priority_queue<double, vector<double>, greater<double> > Q;
            double answer = 1;

            for (int i = 1; i < n; ++i) {
                Q.push(answer * 2);
                Q.push(answer * 3);
                Q.push(answer * 5);
                answer = Q.top();
                while (!Q.empty() && answer == Q.top()) {
                    Q.pop();
                }
            }
            
            return answer;
        }
};

void test_case_1(Solution So) {
    int n = 10;
    int ret = So.nthUglyNumber(n);
    cout << "结果为: " << ret <<endl;
}

int main() {

    Solution So;
    test_case_1(So);
    return 0;
}