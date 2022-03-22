#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
    public:
        array<char, 26> num = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'X', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        /**
         * @brief 从轮数和下标数入手
         *  1. 通过 columnNumber 得到多少轮
         *  2. 然后 columnNumber % 26 得到每轮的下标数
         *  3. 然后需要逆转字符串
         *  4. 但是没有通过校验
         * 
         * @param columnNumber 
         * @return string 
         */
        string convertToTitle(int columnNumber) {
            string ans;
            while (columnNumber > 0) {
                --columnNumber;
                ans += num[columnNumber % 26];
                columnNumber /= 26;
            }
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

void test_case_1(Solution So) {
    int columnNumber = 1;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int columnNumber = 28;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

void test_case_3(Solution So) {
    int columnNumber = 701;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

void test_case_4(Solution So) {
    int columnNumber = 2147483647;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_4(So);
    return 0;
}