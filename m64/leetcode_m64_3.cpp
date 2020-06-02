#include <iostream>
using namespace std;

// 使用了for关键字，不符合限制
class Solution {
    public:
        int sumNums(int n) {
           int sum = 0;       
           for (int i = 1; i <= n; i++) {
               sum += i;
           }
           return sum;
        }
};

void test_case_1(Solution So) {
    int n = 3;
    int ret = So.sumNums(n);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int n = 9;
    int ret = So.sumNums(n);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}