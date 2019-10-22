#include <stdio.h>
#include <stdlib.h>


int mySqrt(int x) { 

    if (x < 1) return 0;
    double a = 1; 
    double check = 0;

    do {
        check = a;
        a = (a + x / a) / 2;
    } while(a != check);
    return (int) a;
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