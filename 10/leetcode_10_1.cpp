#include <iostream>
using namespace std;


class Solution {
    public:
        int pLen;
        int sLen;

        bool helper(int sPos, int pPos, string s, string p) {
            if (pPos == pLen) return (sPos == sLen);

            if (pPos < pLen - 1 && p[pPos + 1] == '*') {
                if (sPos < sLen && (p[pPos] == '.' || s[sPos] == p[pPos])) {
                    return helper(sPos + 1, pPos, s, p) || helper(sPos, pPos + 2, s, p);
                } 
                return helper(sPos, pPos + 2, s, p);
            }

            if (sPos < sLen && (p[pPos] == '.' || s[sPos] == p[pPos])) {
                return helper(sPos + 1, pPos + 1, s, p);
            }
            return false;
        }

        bool isMatch(string s, string p) {
            pLen = p.length();
            sLen = s.length();
            return helper(0, 0, s, p);
        }
};

void test_case_1(Solution So) {
    string s = "aa";
    string p = "a";

    bool ret = So.isMatch(s, p);
    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    string s = "ab";
    string p = ".*";
    bool ret = So.isMatch(s, p);
    cout << "结果为:" << ret << endl;
}

void test_case_3(Solution So) {
    string s = "aab";
    string p = "c*a*b";
    bool ret = So.isMatch(s, p);
    cout << "结果为:" << ret << endl;
}

void test_case_4(Solution So) {
    string s = "ab";
    string p = ".*";
    bool ret = So.isMatch(s, p);
    cout << "结果为:" << ret << endl;
}

void test_case_5(Solution So) {
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    bool ret = So.isMatch(s, p);
    cout << "结果为:" << ret << endl;
}

int main() {

    Solution So;
    test_case_5(So);

    return 0;
}