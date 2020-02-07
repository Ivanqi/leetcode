#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * 暴力法
 *  这种方法中，我们考虑给定字符串中每种可能的非空偶数长度子字符串，检查它是否是一个有效括号字符串序列。为了检查有效性，我们使用了栈方法
 *  每当我们遇到一个'(', 我们把它放在栈顶。对于遇到的每个')', 我们从栈中弹出一个'('
 *  如果栈顶没有'(',或者遍历完整个子字符串后栈仍然有元素，那该子字符串是无效的
 *  这种方法中，我们对每个偶数长度的子字符串都进行判断，并保存目前为止找到的最长的有效子字符串的长度
 * 例子
 *  "((())"
 *  (( --> 无效
 *  (( --> 无效
 *  () --> 有效，长度为 2
 *  )) --> 无效
 *  ((()--> 无效
 *  (())--> 有效，长度为 4
 *  最长长度为 4
 * 时间复杂度: O(n ^ 2)
 * 空间复杂度：O(n)
 */
class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    st.push('(');
                } else if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }
            return st.empty();
        }

        int longestValidParentheses(string s) {
            int maxlen = 0;
            for (int i = 0; i < s.size(); i++) {
                for (int j = i + 2; j <= s.size(); j+=2) {
                    if (isValid(s.substr(i, j))) {
                        maxlen = max(maxlen, j - i);
                    }
                }
            }
            return maxlen;
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
