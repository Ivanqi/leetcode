#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int len = s.length();
            int left = 0, right = len - 1;

            while (left < right) {
                while (left < right && !isalnum(s[left])) {
                    left++;
                }

                while (left < right && !isalnum(s[right])) {
                    right--;
                }

                if (left < right) {
                    if (tolower(s[left]) != tolower(s[right])) return false;
                    ++left;
                    --right;
                }
            }
            return true;
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