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

            int len = good.size();

            int left = 0, right = len - 1;

            while (left < right) {
                if (good[left] != good[right]) {
                    return false;
                }
                left++;
                right--;
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