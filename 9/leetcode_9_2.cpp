#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            /**
             * 特殊情况
             * 如上所述，当x < 0 时，x不是回文数
             * 同样地，如果数字的最后一位是0，为了使该数字为回文
             * 则其第一位数字也应该是0
             * 只有0满足这一属性
             */
            if (x < 0 || (x % 10 == 0 && x != 0)) {
                return false;
            }

            int revertedNumber = 0;
            while (x > revertedNumber) {
                revertedNumber = revertedNumber * 10 + x % 10;
                x /= 10;
            }

            /**
             * 当数字长度为奇数时，我们可以通过 revertedNumber / 10 去除处于中位的数字
             * 例如，当输入为12321时，在while 循环的末尾我们可以得到x = 12， revertedNumber = 123,
             * 由于处于中位的数字不影响回文(它总是与自己相等)，所以我们可以简单地将其去除
             */
            return x == revertedNumber || x == revertedNumber / 10;
        }
};

void test_case_1(Solution So) {
    int x = 121;
    bool ret = So.isPalindrome(x);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    int x = -121;
    bool ret = So.isPalindrome(x);
    cout << "结果为: " << ret << endl;
}

int main() {
    
    Solution So;
    test_case_1(So);
    return 0;
}