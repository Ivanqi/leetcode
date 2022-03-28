#include <iostream>
using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t rev = 0;
            for (int i = 0; i < 32 && n > 0; ++i) {
                rev |= (n & 1) << (31 - i);
                cout << "rev: " << rev << endl;
                n >>= 1;
            }
            return rev;
        }
};

void test_case_1(Solution So) {
    uint32_t n = 4294967293;
    uint32_t ret = So.reverseBits(n);
    cout << "结果为: " << ret << endl;
}

int main() {
    Solution So;
    test_case_1(So);
    return 0;
}