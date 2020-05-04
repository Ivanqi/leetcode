#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


class Solution {
    public:

        bool isMatch(string s, string p) {
            s=" "+s;//防止该案例：""\n"c*"
            p=" "+p;
            int sLen = s.size();
            int pLen = p.size();

            bool dp[sLen + 1][pLen + 1];
            memset(dp, false, (sLen + 1) * (pLen + 1));
            dp[0][0] = true;

            for (int i = 1; i <= sLen; i++) {
                for (int j = 1; j <= pLen; j++) {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else if (p[j - 1] == '*') {
                        if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                            dp[i][j] = dp[i][j - 2];
                        } else {
                            dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                        }
                    }
                }
            }
            return dp[sLen][pLen];
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
    test_case_3(So);

    return 0;
}