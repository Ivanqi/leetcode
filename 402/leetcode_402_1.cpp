#include <iostream>
using namespace std;
class Solution {
    public:
        string removeKdigits(string num, int k) {
            string res;
            int n = num.size(), m = n - k;
            for (char c: num) {
                while (k && res.size() && res.back() > c) {
                    res.pop_back();
                    --k;
                }
                res.push_back(c);
            }
            res.resize(m);
            // 去除前导0， 如果10200， k = 1
            while (!res.empty() && res[0] == '0') {
                res.erease(res.begin());
            }
            return res.empty() ? '0' : res;
        }
}
void test_case_1(Solution So) {
    string num("1432219");
    int k = 3;

    cout << So.removeKdigits(num, k) << endl;;
}

void test_case_2(Solution So) {
    string num("10200");
    int k = 1;
    cout << So.removeKdigits(num, k) << endl;;
}

void test_case_3(Solution So) {
    string num("10");
    int k = 2;
    cout << So.removeKdigits(num, k) << endl;
}

void test_case_4(Solution So) {
    string num("112");
    int k = 1;
    cout << So.removeKdigits(num, k) << endl;
}

int main() {
    Solution So;
    test_case_4(So);
    return 0;
}