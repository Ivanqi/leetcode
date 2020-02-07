#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 不需要额外的空间
 *  在这种方法中，利用两个计数器left 和 right
 *  首先，我们从左到右遍历字符串，对于遇到的每个'('。我们增加left计算器，对于遇到每个')',我们增加right计数器
 *  每当left计数器与right计数器相等时，我们计算当时有效字符串的长度，并且记录目前为止找到的最长字符串
 *  如果right计数器比left计数器大时，我们将left和right计数器同时变成0
 *  
 *  接下来，我们从右到左做一遍类似的工作
 */
class Solution {
    public:
        int longestValidParentheses(string s) {
            int left = 0, right = 0, maxlength = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    left++;
                } else {
                    right++;
                }

                if (left == right) {
                    maxlength = max(maxlength, 2 * right);
                } else if (right >= left) {
                    left = right = 0;
                }
            }

            left = right = 0;
            for (int i = s.size() -1; i >= 0; i--) {
                if (s[i] == '(') {
                    left++;
                } else {
                    right++;
                }

                if (left == right) {
                    maxlength = max(maxlength, 2 * left);
                } else if (left >= right) {
                    left = right = 0;
                }
            }
            return maxlength;
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
    test_case_2(So);
}