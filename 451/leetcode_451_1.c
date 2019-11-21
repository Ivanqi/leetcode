#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * frequencySort(char * s){
    int check[128] = {0};
    int len = strlen(s);
    int i;

    char* ret = (char*)malloc(len + 1);
    memset(ret, 0, len + 1);
    // 计算词频
    for (i = 0; i < strlen(s); i++) check[s[i]]++;

    // 排序
    int max = -1;
    int pos = -1;
    int now = 0;
    while (max != 0) {
        max = -1;
        pos = -1;

        for (i = 0; i < 128; i++) {
            if (check[i] > max) {
                max = check[i], pos = i;
            }
        }

        for (i = 0; i < max; i++) {
            ret[now++] = pos;
        }

        check[pos] = 0;
    }

    ret[now] = 0;
    return ret;
}


void test_case_1() {

    char *s = "tree";
    char *ret = frequencySort(s);

    int i;
    for (i = 0; i < strlen(ret); i++) {
        printf("%c", ret[i]);
    }
}

void test_case_2() {

    char *s = "cccaaa";
    char *ret = frequencySort(s);

    int i;
    for (i = 0; i < strlen(ret); i++) {
        printf("%c", ret[i]);
    }
}

void test_case_3() {

    char *s = "Aabb";
    char *ret = frequencySort(s);

    int i;
    for (i = 0; i < strlen(ret); i++) {
        printf("%c", ret[i]);
    }
}

int main() {
    test_case_3();
}