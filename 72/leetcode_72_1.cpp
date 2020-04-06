#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define printState(states, n, w) \
    for (int i = 0; i < n; ++i) { \
        for (int j = 0; j < w; ++j) { \
            printf("%d ", states[i][j]); \
        } \
        printf("\n"); \
    }

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int word1_len = word1.size();
            int word2_len = word2.size();

            if (word1_len == 0 && word2_len == 0) return 0;
            if (word1_len == 0 && word2_len > 0) return word2_len;
            if (word1_len > 0 && word2_len ==  0) return word1_len;

            int states[word1_len][word2_len];

            for (int i = 0; i < word1_len; i++) {
                for (int j = 0; j < word2_len; j++) {
                    states[i][j] = 0;
                }
            }


            for (int i = 0; i < word1_len; i++) {
                if (word1[i] == word2[0]) states[i][0] = i;
                else if (i != 0) states[i][0] = states[i - 1][0] + 1;
                else states[i][0] = 1;
            }

            for (int j = 0; j < word2_len; j++) {
                if (word2[j] == word1[0]) states[0][j] = j;
                else if (j != 0) states[0][j] = states[0][j - 1] + 1;
                else states[0][j] = 1;
            }

            for (int i = 1; i < word1_len; i++) {
                for (int j = 1; j < word2_len; j++) {
                    int n1 = states[i - 1][j] + 1;
                    int n2 = states[i][j - 1] + 1;
                    int n3 = states[i - 1][j - 1];
                    
                    if (word1[i] == word2[j]) {                        
                        int minx = min(min(n1, n2), min(n1, n3));
                        states[i][j] = minx;
                    } else {
                        n3 = n3 + 1;
                        int minx = min(min(n1, n2), min(n1, n3));
                        states[i][j] = minx;
                    }
                }
            }

            return states[word1_len - 1][word2_len - 1];
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
    test_case_3(So);
}