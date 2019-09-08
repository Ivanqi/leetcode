#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
        int calPoints(vector<string>& ops) {
            if (ops.size() == 0) return 0;
            int ans = 0;
            stack<int> s;
            for (int i = 0; i < ops.size(); ++i) {
                if (ops[i] == "+") {
                    int top = s.top(); s.pop();
                    int newtop;
                    if (s.size() > 0) {
                        newtop = top + s.top();
                    } else {
                        newtop = top + 0;
                    }
                    s.push(top);
                    s.push(newtop);
                } else if (ops[i] == "D") {
                    s.push(s.top() * 2);
                } else if (ops[i] == "C"){
                    s.pop();
                } else {
                    s.push(stoi(ops[i]));
                }
            }
            while (!s.empty()) {
                ans += s.top();
                s.pop();
            }
            return ans;
        }
};

void test_case_1(Solution So) {
    vector<string> V;
    V.push_back("5");
    V.push_back("2");
    V.push_back("C");
    V.push_back("D");
    V.push_back("+");

    cout << "val :" << So.calPoints(V) << endl;
}

void test_case_2(Solution So) {
    vector<string> V;
    V.push_back("5");
    V.push_back("-2");
    V.push_back("4");
    V.push_back("C");
    V.push_back("D");
    V.push_back("9");
    V.push_back("+");
    V.push_back("+");

    cout << "val :" << So.calPoints(V) << endl;
}

void test_case_3(Solution So) {
    vector<string> V;
    V.push_back("5");
    V.push_back("+");
    V.push_back("2");
    V.push_back("C");
    V.push_back("D");
    V.push_back("+");

    cout << "val :" << So.calPoints(V) << endl;
}

int main () {

    Solution So;
    test_case_3(So);
    return 0;
}