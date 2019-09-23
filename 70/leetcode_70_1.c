#include <stdlib.h>
#include <stdio.h>

int main() {
    int F[10];
    int n = 5;
    F[0] = F[1] = 1;

    for (int i = 2; i <= n; i++) F[i] = F[i - 1] + F[i - 2];

    printf("val: %d", F[n]);
    return 0;
}