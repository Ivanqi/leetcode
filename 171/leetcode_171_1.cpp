#include <iostream>
using namespace std;

class Solution {
    public:
        /**
         * @brief 计算方式
         *  columnTitle=“FXSHRXW” , 对应的序号分别是：[6,24,19,8,18,24,23][6,24,19,8,18,24,23]
         *  23 * 26 ^ 0 + 24 * 26 ^ 1 + 18 * 26 ^ 2 + 8 * 26 ^ 3 + 19 * 26 ^ 4 + 24 * 26 ^ 5 + 6 * 26 ^ 6 = 2147483647
         * 
         * @param columnTitle 
         * @return int 
         */
        int titleToNumber(string columnTitle) {
            int number = 0;
            int multiple = 1;
            for (int i = columnTitle.size() - 1; i >= 0; i--) {
                int k = columnTitle[i] - 'A' + 1;
                number += k * multiple;
                multiple *= 26;
            }

            return number;
        }
};

void test_case_1(Solution So) {
    string columnTitle = "A";
    int ret = So.titleToNumber(columnTitle);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    string columnTitle = "AB";
    int ret = So.titleToNumber(columnTitle);
    cout << "结果为: " << ret << endl;
}

void test_case_3(Solution So) {
    string columnTitle = "FXSHRXW";
    int ret = So.titleToNumber(columnTitle);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}