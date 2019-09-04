#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

bool isVaild(char *s) {
    if (s == NULL || s[0] == '\0') return true;
    char stack[10240]; 
    int top = 0;
    int i;
    for (i = 0; s[i]; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[top++] = s[i];
        else {
            if ((--top) < 0) return false;
            if (s[i] == ')' && stack[top] != '(') return false;
            if (s[i] == ']' && stack[top] != '[') return false;
            if (s[i] == '}' && stack[top] != '{') return false;
        }
    }
    return (top ? false : true);
}

bool test_str1() {
    char str[] = "()";
    return isVaild(str);
}

bool test_str2() {
    char str[] = "()[]{}";
    return isVaild(str);
}

bool test_str3() {
    char str[] = "(]";
    return isVaild(str);
}

bool test_str4() {
    char str[] = "([)]";
    return isVaild(str);
}

bool test_str5() {
    char str[] = "{[]}";
    return isVaild(str);
}

bool test_str6() {
    char str[] = "(((((())))))";
    return isVaild(str);
}

bool test_str7() {
    char str[] = "(((((((()";
    return isVaild(str);
}

int main () {
    bool res;
    res = test_str6();

    if (res) {
        printf("成功\n");
    } else {
        printf("失败\n");
    }
    return 0;
}