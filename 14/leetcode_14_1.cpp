#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int strs_len = strs.size();
            if (strs_len == 1)  return strs[0];
            int i, j;
            j = 0;
            for (i = 0; i < strs_len && strs[i][j] != '\0'; i++) {
                if (strs[i][j] != strs[i + 1][j]) {
                    break;
                }
                if (i == strs_len - 2) {
                    i = -1;
                    ++j;
                }
            }

            string tmp;
            for (i = 0; i < j; i++) {
                tmp += strs[0][i];
            }

            return tmp;
        }
};

void test_case_1(Solution So) {
    vector<string> strs = {
        "flower", "flow", "flight"
    };

    string ret = So.longestCommonPrefix(strs);
    cout << ret << endl;
}

void test_case_2(Solution So) {
    vector<string> strs = {
        "dog", "racecar", "car"
    };

    string ret = So.longestCommonPrefix(strs);
    cout << ret << endl;
}

void test_case_3(Solution So) {
    vector<string> strs = {
        "a"
    };
    string ret = So.longestCommonPrefix(strs);
    cout << ret << endl;
} 

int main () {
    Solution So;
    test_case_3(So);
}