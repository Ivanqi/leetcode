#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isUgly(int num) {
            if (num < 1) return false;
            return search(num);
        }

        bool search(int num) {
            if (num == 1) {
                return true;
            }

            if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) {
                return false;   // 不是 2, 3, 5的倍数，说明这条路走不通，返回上一层
            } else {
                return num % 2 == 0 ? search(num / 2) : false || num % 3 == 0 ? search(num / 3) : false || num % 5 == 0 ? search(num / 5) : false;
            }
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

void test_case_4(Solution So) {
    int num = 5;
    bool ret = So.isUgly(num);
    cout << "结果为: " << ret <<endl;
}

int main() {

    Solution So;
    test_case_4(So);
    return 0;
}