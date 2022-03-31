#include <iostream>
using namespace std;

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int ret = 0;
            while (n) {
                n &= n - 1;
                ret++;
            }
            return ret;
        }
};

void test_case_1 (Solution So) {
    uint32_t n = 7;
    int ret = So.hammingWeight(n);
    cout << "结果: " << ret << endl;
}

void test_case_2(Solution So) {
    uint32_t n = 128;
    int ret = So.hammingWeight(n);
    cout << "结果: " << ret << endl;
}

void test_case_3(Solution So) {
    uint32_t n = 6;
    int ret = So.hammingWeight(n);
    cout << "结果: " << ret << endl;
}

int main() {
    Solution So;
    test_case_3(So);
    return 0;
}