#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            int len = s.length();
            unordered_map<int, int> m;
            for (char ch: s) {
                m[ch]++;
            }

            for (int i = 0; i < len; i++) {
               if (m[s[i]] == 1) {
                   return i;
               }
            }

            return -1;
        }
};

void test_case_1(Solution So) {
    string s = "leetcode";
    int ret = So.firstUniqChar(s);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    string s = "loveleetcode";
    int ret = So.firstUniqChar(s);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}