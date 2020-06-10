#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            string str = to_string(x);
            int j, len;
            j = len = str.length();
            j -= 1;
            for (int i = 0; i < len; i++) {
                if (str[i] != str[j - i]) {
                    return false;
                }
            }
            return true;
        }
};

void test_case_1(Solution So) {
    int x = 121;
    bool ret = So.isPalindrome(x);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int x = -121;
    bool ret = So.isPalindrome(x);
    cout << "结果为: " << ret << endl;
}

int main() {
    
    Solution So;
    test_case_1(So);
    return 0;
}