#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.length();
            int m = text2.length();

            if (n * m == 0) return n + m;

            int states[n][m];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    states[i][j] = 0;
                }
            }

            for (int i = 0; i < n; i++) {
                if (text1[i] == text2[0]) states[i][0] = 1;
                else if (i != 0) states[i][0] = states[i - 1][0];
                else states[i][0] = 0;
            }

            for (int j = 0; j < m; j++) {
                if (text2[j] == text1[0]) states[0][j] = 1;
                else if (j != 0) states[0][j] = states[0][j - 1];
                else states[0][j] = 0;
            }

            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    int left = states[i - 1][j];
                    int down = states[i][j - 1];
                    int left_down = states[i - 1][j - 1];
                    if (text1[i] == text2[j]) {
                        left_down = left_down + 1;
                        int maxNums = max(left, max(down ,left_down));
                        states[i][j] = maxNums;
                    } else {
                        int maxNums = max(left, max(down ,left_down));
                        states[i][j] = maxNums;
                    }
                }
            }

            return states[n - 1][m - 1];
        }
};

void test_case_1(Solution So) {
    string text1 = "abcde";
    string text2 = "ace";

    int ret =So.longestCommonSubsequence(text1, text2);

    cout << "结果为:" << ret << endl;
}

int main () {

    Solution So;
    test_case_1(So);
    return 0;
}