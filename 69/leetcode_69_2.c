#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x){
    if (x < 1) return x; 

    long left = 1;
    long right = x;

    long mid;

    while (left < right - 1) {
        mid = (left + right) / 2;
        if (mid * mid > x) {
            right = mid;
        } else if (mid * mid < x) {
            left = mid;
        } else {
            return mid;
        }
    }
    return left;
}

void test_case_1() {
    printf("%d\n",mySqrt(4));
}

void test_case_2() {
    printf("%d\n",mySqrt(8));
}

void test_case_3() {
    printf("%d\n",mySqrt(1));
}


int main() {
    
    test_case_3();
    return 0;
}