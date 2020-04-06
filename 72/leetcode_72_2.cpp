#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n = word1.length();
            int m = word2.length();

            // 有一个字符为空串
            if (n * m == 0) return n + m;

            // DP数组
            int D[n + 1][m + 1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    D[i][j] = 0;
                }
            }

            // 边界初始化
            for (int i = 0; i < n + 1; i++) {
                D[i][0] = i;
            }

            for (int j = 0; j < m + 1; j++) {
                D[0][j] = j;
            }

            // 计算所有DP值
            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < m + 1; j++) {
                    int left = D[i - 1][j] + 1;
                    int down = D[i][j - 1] + 1;
                    int left_down = D[i - 1][j - 1];
                    if (word1[i - 1] != word2[j - 1]) left_down += 1;
                    D[i][j] = min(left, min(down, left_down));
                }
            }
            return D[n][m];
        }
};

void test_case_1(Solution So) {
    string word1 = "horse";
    string word2 = "ros";
    int ret = So.minDistance(word1, word2);
    cout << "结果为:" << ret << endl;
}

void test_case_2(Solution So) {
    string word1 = "";
    string word2 = "aab";

    int ret = So.minDistance(word1, word2);
    cout << "结果为:" << ret << endl;
}

void test_case_3(Solution So) {
    string word1 = "b";
    string word2 = "";

    int ret = So.minDistance(word1, word2);
    cout << "结果为:" << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);
}
