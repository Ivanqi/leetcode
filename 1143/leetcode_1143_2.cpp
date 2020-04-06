#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
     public:
        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.length();
            int m = text2.length();

            if (n * m == 0) return n + m;

            int states[n + 1][m + 1];

            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < m + 1; j++) {
                    states[i][j] = 0;
                }
            }

            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < m + 1; j++) {
                    if (text1[i - 1] == text2[j - 1]) {
                        states[i][j] = states[i - 1][j - 1] + 1;
                    } else {
                        states[i][j] = max(states[i - 1][j], states[i][j - 1]);
                    }
                }
            }
            return states[n][m];
        }
};


void test_case_1(Solution So) {
    string text1 = "abcde";
    string text2 = "ace";

    int ret =So.longestCommonSubsequence(text1, text2);

    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    string text1 = "abc";
    string text2 = "def";

    int ret =So.longestCommonSubsequence(text1, text2);

    cout << "结果为:" << ret << endl;
}

int main () {

    Solution So;
    test_case_2(So);
    return 0;
}