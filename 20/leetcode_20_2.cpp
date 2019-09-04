#include <iostream>
#include <string>
#include<stack>
using namespace std;


bool isValid(string s) {
    stack<char> st;
    int i;
    for (i = 0; i < s.size(); i++) {
        if (st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) return false;
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (s[i] - st.top() == 1 || s[i] - st.top() == 2) {
                st.pop();
            } else {
                return false;
            }
        } else {
            st.push(s[i]);
        }
    }
    return st.empty();
}


bool test_str1() {
    char str[] = "()";
    return isValid(str);
}

bool test_str2() {
    char str[] = "()[]{}";
    return isValid(str);
}

bool test_str3() {
    char str[] = "(]";
    return isValid(str);
}

bool test_str4() {
    char str[] = "([)]";
    return isValid(str);
}

bool test_str5() {
    char str[] = "{[]}";
    return isValid(str);
}

bool test_str6() {
    char str[] = "(((((())))))";
    return isValid(str);
}

bool test_str7() {
    char str[] = "(((((((()";
    return isValid(str);
}

bool test_str8() {
    char str[] = ")))))";
    return isValid(str);
}
int main () {

    bool res;
    res = test_str8();

    if (res) {
        cout << "成功" << endl;
    } else {
        cout << "失败" << endl;
    }
    return 0;
}