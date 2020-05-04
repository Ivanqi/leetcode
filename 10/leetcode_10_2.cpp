#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            if (p.empty()) return s.empty();

            auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

            if (p.length() >= 2 && p[1] == '*') {
               return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
            } else {
                return first_match && isMatch(s.substr(1), p.substr(2));
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