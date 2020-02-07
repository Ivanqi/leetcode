#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
class Solution {
    public:
        int longestValidParentheses(string s) {
            int maxans = 0;
            stack<int> st;
            st.push(-1);
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    st.push(i);
                } else {
                    st.pop();
                    if (st.empty()) {
                        st.push(i);
                    } else {
                        maxans = max(maxans, i - st.top());
                    }
                }
            }
            return maxans;
        }
};

void test_case_1(Solution So) {    
    string str = "(()";
    int num = So.longestValidParentheses(str);

    cout << "有效括号数量:" << num << endl;
}
void test_case_2(Solution So) {
    string str = ")()())";
    int num = So.longestValidParentheses(str);

    cout << "有效括号数量:" << num << endl;
}

void test_case_3(Solution So) {
    string str = "())(())";
    int num = So.longestValidParentheses(str);
    cout << "有效括号数量:" << num << endl;
}

void test_case_4(Solution So) {
    string str = "((())";
    int num = So.longestValidParentheses(str);
    cout << "有效括号数量:" << num << endl;
}


int main() {
    Solution So;
    test_case_4(So);
}