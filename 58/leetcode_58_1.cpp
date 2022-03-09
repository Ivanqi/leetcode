#include <iostream>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int sLen = s.length() - 1;

            while (s[sLen] == ' ') {
                sLen--;
            }
            
            int idx = 0;
            while (sLen >= 0 && s[sLen] != ' ') {
                idx++;
                sLen--;
            }

            return idx;
        }
};

void test_case_1(Solution So) {
    string s = "Hello World";
    int ret = So.lengthOfLastWord(s);
    cout << "结果为: " << ret << endl; 
}

void test_case_2(Solution So) {
    string s = "   fly me   to   the moon  ";
    int ret = So.lengthOfLastWord(s);
    cout << "结果为: " << ret << endl; 
}

void test_case_3(Solution So) {
    string s = "luffy is still joyboy";
    int ret = So.lengthOfLastWord(s);
    cout << "结果为: " << ret << endl; 
}

void test_case_4(Solution So) {
    string s = "a";
    int ret = So.lengthOfLastWord(s);
    cout << "结果为: " << ret << endl; 
}

int main() {
    Solution So;
    test_case_4(So);
    return 0;
}