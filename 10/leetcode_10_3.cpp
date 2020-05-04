#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            return isMatch(s.c_str(), p.c_str());
        }

        bool isMatch(const char* s, const char* p) {
            if (*p == 0) return *s == 0;

            auto first_match = *s && (*s == *p || *p == '.');

            if (*(p + 1) == '*') {
                return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
            } else {
                return first_match && isMatch(++s, ++p);
            }
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

int main() {

    Solution So;
    test_case_3(So);

    return 0;
}