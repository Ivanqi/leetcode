#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int memo[50][50] = {{0,},};
        int flag[50][50] = {{0,},};

        bool helper(int i, int j, string s, string p) {

            bool ret;

            if (flag[i][j]) return memo[i][j];
            if (!p[j]) return (!s[i]);

            bool first = s[i] && (s[i] == p[j] || p[j] == '.');

            if (p[j + 1] == '*') {
                ret = helper(i, j + 2, s, p) || (first && helper(i + 1, j, s, p));
            } else {
                ret = first && helper(i + 1, j + 1, s, p);
            }
            memo[i][j] = ret;
            flag[i][j] = 1;
            return ret;
        }

        bool isMatch(string s, string p) {
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
    string s = "aaaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";
    bool ret = So.isMatch(s, p);
    cout << "结果为:" << ret << endl;
}

int main() {

    Solution So;
    test_case_4(So);

    return 0;
}