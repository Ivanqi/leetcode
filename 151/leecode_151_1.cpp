#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        string reverseWords(string s) {
            int n = s.length();
            vector<string> tmp;
            string a;
            for (int i = 0; i < n + 1; i++) {
                if (s[i] == ' ' || (i == n)) {
                    if (a != "") {
                        tmp.push_back(a);
                    }
                    a = "";
                } else {
                    a += s[i];
                }
            }
            a = "";
            for (int j = tmp.size() - 1; j >= 0; j--) {
              a += tmp[j] + ' ';
            }
            return a.substr(0, a.length() - 1);
        }
};

void test_case_1(Solution So) {
    string s = "the sky is blue";
    string ret = So.reverseWords(s);
    cout << ret << endl;
}

void test_case_2(Solution So) {
    string s = "  hello world!  ";
    string ret = So.reverseWords(s);
    cout << ret << endl;
}

void test_case_3(Solution So) {
     string s = "a good   example";
    string ret = So.reverseWords(s);
    cout << ret << endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}