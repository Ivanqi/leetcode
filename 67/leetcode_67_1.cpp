#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int i = a.length() - 1;
            int j = b.length() - 1;
            int carry = 0;
            string res;

            while (i >= 0 || j >= 0 || carry != 0) {
                int digitA = i >= 0 ? a[i] - '0' : 0;
                int digitB = j >= 0 ? b[j] - '0' : 0;
                int sum = digitA + digitB + carry;
                carry = sum >= 2 ? 1 : 0;

                sum = sum >= 2 ? sum - 2 : sum;

                res += to_string(sum);
                
                i--;
                j--;
            }

            reverse(res.begin(), res.end());
            return res;
        }
};

void test_case_1(Solution So) {
    string a = "11";
    string b = "1";

    string ret = So.addBinary(a, b);
    cout << ret << endl;
}

void test_case_2(Solution So) {
    string a = "1010";
    string b = "1011";

    string ret = So.addBinary(a, b);
    cout << ret << endl;
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}