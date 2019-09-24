#include <stdio.h>

int fib(int N) {
    int F[100];
    F[0] = 0;
    F[1] = 1;
    int i;
    for (i = 2; i <= N; i++) F[i] = F[i - 1] + F[i - 2];
    return F[N];
}

int fib2(int N) {
    if (N < 2) return N;
    int prev = 0, curr = 1;
    int i;
    for (i = 0; i < N - 1; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

test_case_1() {
    printf("val: %d\n", fib2(2));
}

test_case_2() {
    printf("val: %d\n", fib2(3));
}

test_case_3() {
    printf("val: %d\n", fib2(4));
}

int main() {
   test_case_3();
}