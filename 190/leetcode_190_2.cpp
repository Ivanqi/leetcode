#include <iostream>
using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            n = (n >> 16) | (n << 16);
            n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
            n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
            n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
            n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
            return n;
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