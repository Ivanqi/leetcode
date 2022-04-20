#include <iostream>
using namespace std;

class Solution {
    public:
        // 解答: x*100+y*10+z=x*99+y*9+x+y+z
        int addDigits(int num) {
            return (num - 1) % 9 + 1;
        } 
};