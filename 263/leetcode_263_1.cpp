#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isUgly(int num) {
            while (num) {
                if (num % 2 == 0) num /= 2;
                else if (num % 3 == 0) num /= 3;
                else if (num % 5 == 0) num /=5;
                else break;
            }
            return num == 1;
        }
};

void test_case_1(Solution So) {
    int num = 6;
    bool ret = So.isUgly(num);
    cout << "结果为: " << ret <<endl;
}

void test_case_2(Solution So) {
    int num = 8;
    bool ret = So.isUgly(num);
    cout << "结果为: " << ret <<endl;
}

void test_case_3(Solution So) {
    int num = 14;
    bool ret = So.isUgly(num);
    cout << "结果为: " << ret <<endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}