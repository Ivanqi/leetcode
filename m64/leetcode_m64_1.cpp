#include <iostream>
using namespace std;

class Solution {
    public:
        int sumNums(int n) {
            int sum = n;
            bool flag = n > 0 && (sum += sumNums(n - 1)) > 0;
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