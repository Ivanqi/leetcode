#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        /*
            因为x % 26=[0,25] 但是我们取从[1-26]对应[A-Z] 直接取模 26%26=0 不在我们范围内
            所以我们采用-1 [0-25]对应[A-Z] (26-1)%26 =25 25+'A'='Z'
        */
        string convertToTitle(int columnNumber) {
            string ans;
            while (columnNumber > 0) {
                --columnNumber;
                ans += columnNumber % 26 + 'A';
                columnNumber /= 26;
            }
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

void test_case_1(Solution So) {
    int columnNumber = 1;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int columnNumber = 28;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

void test_case_3(Solution So) {
    int columnNumber = 701;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

void test_case_4(Solution So) {
    int columnNumber = 2147483647;
    string ret = So.convertToTitle(columnNumber);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_4(So);
    return 0;
}