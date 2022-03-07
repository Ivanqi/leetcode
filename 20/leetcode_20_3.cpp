#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return false;

        stack<char> st;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;

            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (s[i] - st.top() == 1 || s[i] - st.top() == 2) {
                    st.pop();
                } else {
                    return false;
                }
            }  else {
                st.push(s[i]);
            }
            
        }

        return st.empty();
    }
};

bool test_str1(Solution So) {
    char str[] = "()";
    return So.isValid(str);
}

bool test_str2(Solution So) {
    char str[] = "()[]{}";
    return So.isValid(str);
}

bool test_str3(Solution So) {
    char str[] = "(]";
    return So.isValid(str);
}

bool test_str4(Solution So) {
    char str[] = "([)]";
    return So.isValid(str);
}

bool test_str5(Solution So) {
    char str[] = "{[]}";
    return So.isValid(str);
}

bool test_str6(Solution So) {
    char str[] = "(((((())))))";
    return So.isValid(str);
}

bool test_str7(Solution So) {
    char str[] = "(((((((()";
    return So.isValid(str);
}

bool test_str8(Solution So) {
    char str[] = ")))))";
    return So.isValid(str);
}
int main () {

    bool res;
    Solution So;
    res = test_str1(So);

    if (res) {
        cout << "成功" << endl;
    } else {
        cout << "失败" << endl;
    }
    return 0;
}