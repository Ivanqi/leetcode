#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string good;
            for (char ch: s) {
                if (isalnum(ch)) {
                    good += tolower(ch);
                }
            }

            string googReverse(good.rbegin(), good.rend());
            return good == googReverse ? true : false;
        }
};

void test_case_1(Solution So) {
    string s = "A man, a plan, a canal: Panama";
    bool ret = So.isPalindrome(s);
    cout << "结果: " << ret << endl;
}

void test_case_2(Solution So) {
    string s = "race a car";
    bool ret = So.isPalindrome(s);
    cout << "结果: " << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
}