#include <stdio.h>
#include <stdlib.h>

// 失败案例
int longestValidParentheses(char * s){
    if (s == NULL || s[0] == '\0') return 0;
    int top = 0;
    char stack[1024];
    int i;
    
    for (i = 0; s[i]; i++) {
        if (s[i] == '(') {
            if (top <= 0) {
                stack[top++] = s[i];
            } else if (top > 0 && stack[top] == s[i]){
                continue;
            }
        } else if (top > 0 && s[i] == ')' && stack[top] != s[i]) {
            stack[top++] = s[i];
        }
    }

    return top;
}

void test_case_1() {    
    char str[] = "(()";
    int num = longestValidParentheses(str);

    printf("有效括号数量:%d\n", num);
}

void test_case_2() {
    char str[] = ")()())";
    int num = longestValidParentheses(str);

    printf("有效括号数量:%d\n", num);
}


int main() {
    test_case_2();
}