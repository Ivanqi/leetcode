#include <iostream>
using namespace std;

// 暴力法
class Solution {
    public:
        int nthUglyNumber(int n) {
            int count = 0;
            int result = 1;

            while (count < n) {
                if (isUgly(result)) {
                    count++;
                }
                result++;
            }
            // result 多加了1
            return result - 1;
        }

        bool isUgly(int num) {
            if (num <= 0) return false;

            while (num) {
                if (num % 2 == 0) num /= 2;
                else if (num % 3 == 0) num /= 3;
                else if (num % 5 == 0) num /= 5;
                else break;
            }

            return num == 1;
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