#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        unordered_map<char, int> symbolValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

    public:
        int romanToInt(string s) {
            int len = s.length();
            int ans = 0;

            /**
             * 规则：如果当前值小于下一个的值，就执行减法
             */
            for (int i = 0; i < len; ++i) {
               int value = symbolValues[s[i]];
                if (i < len - 1 && value < symbolValues[s[i + 1]]) {
                   ans -= value;
                } else {
                   ans += value;
                }
            }

            return ans;
        }
};

void test_case_1(Solution So) {
    string s = "III";
    string p = "a";

    int ret = So.romanToInt(s);
    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    string s = "IV";
    string p = "a";

    int ret = So.romanToInt(s);
    cout << "结果为:" << ret << endl;
}

void test_case_3(Solution So) {
    string s = "IV";
    string p = "a";

    int ret = So.romanToInt(s);
    cout << "结果为:" << ret << endl;
}


int main () {
    Solution So;
    test_case_1(So);
}