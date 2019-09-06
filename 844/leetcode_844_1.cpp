#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;

        int i;
        for (i = 0; i < S.length(); i++) {
            if (S[i] == '#') {
                if (s.empty()) {
                    continue;
                } else {
                    s.pop();
                }
            } else {
                s.push(S[i]);
            }
        }

        for (i = 0; i < T.length(); i++) {
            if (T[i] == '#') {
                if (t.empty()) {
                    continue;
                } else {
                    t.pop();
                }
            } else {
                t.push(T[i]);
            }
        }

        if (s.size() != t.size()) return false;
        for(i = 0; i < s.size(); i++) {
            if(s.top() == t.top()) {
                s.pop();
                t.pop();
            }
            else return false;
        }
        return true;
    }
};

void test_case_1(Solution s) {
    char S[] = "ab#c";
    char T[] = "ad#c";
    if (s.backspaceCompare(S, T)) {
        cout << "Success" << endl;
    } else {
        cout << "Error" << endl;
    }
}

void test_case_2(Solution s) {
    char S[] = "ab##";
    char T[] = "c#d#";
    if (s.backspaceCompare(S, T)) {
        cout << "Success" << endl;
    } else {
        cout << "Error" << endl;
    } 
}

void test_case_3(Solution s) {
    char S[] = "a##c";
    char T[] = "#a#c";
    if (s.backspaceCompare(S, T)) {
        cout << "Success" << endl;
    } else {
        cout << "Error" << endl;
    } 
}

void test_case_4(Solution s) {
    char S[] = "a#c";
    char T[] = "b";
    if (s.backspaceCompare(S, T)) {
        cout << "Success" << endl;
    } else {
        cout << "Error" << endl;
    } 
}

int main ()
{
    Solution s;
    test_case_4(s);
    return 0;
}