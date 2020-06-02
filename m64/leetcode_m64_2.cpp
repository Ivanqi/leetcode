#include <iostream>
using namespace std;

// 使用了乘除法，不符合限制
class Solution {
    public:
        int sumNums(int n) {
           return (1 + n) * n / 2;         
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