#include <iostream>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            int i = 0, j = 0;

            int hLen = haystack.length();
            int nLen = needle.length();

            while (i < hLen && j < nLen) {
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                } else {
                    i = i - j + 1;
                    j = 0;
                }
            }

            if (j == nLen) {
                return i - nLen;
            }

            return -1;
        }
};

void test_case_1(Solution So) {

    string haystack = "hello";
    string needle = "ll";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

void test_case_2(Solution So) {

    string haystack = "aaaaa";
    string needle = "bba";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

void test_case_3(Solution So) {

    string haystack = "";
    string needle = "";
    
    int ret = So.strStr(haystack, needle);
    
    cout << "结果:" << ret << endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}