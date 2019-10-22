#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x){
    long i = 0;
    long j = x / 2 + 1; // 对于一个非负数，它的平方根不会大于(n / 2 + 1)

    while (i <= j) {
        long mid = (i + j) / 2;
        long res = mid * mid;
        if (res == x) return mid;
        else if (res < x) i = mid + 1;
        else j = mid - 1;
    }

    return j;
}

void test_case_1() {
    printf("%.d\n",mySqrt(4));
}

void test_case_2() {
    printf("%.d\n",mySqrt(8));
}


int main() {
    
    test_case_2();
    return 0;
}