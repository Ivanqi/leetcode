#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

class Solution {
    private:
        stack<int> num;
        stack<char> op;
        int pri(char a){
            switch(a){
                case '+': return 1;
                case '-': return 1;
                case '*': return 2;
                case '/': return 2;
                case '(': return 3;
                default: return -1;
            }
        }
        void cal(){
            int b = num.top(); num.pop();
            int a = num.top(); num.pop();
            switch(op.top()){
                case '+': num.push(a+b); break;
                case '-': num.push(a-b); break;
                case '*': num.push(a*b); break;
                case '/': num.push(a/b); break;
            }
            op.pop();
        }
    public:
        int calculate(string s) {
            string ss;
            for (int i = 0; i < (int)s.size(); i++) {
                if (isdigit(s[i])) {
                    ss+=s[i];
                }
                else if(s[i]==' ') continue;
                else{
                    if(!ss.empty()) {
                        num.push(stoi(ss));
                        ss.clear();
                    }
                    if (op.empty() || s[i] == '(' || pri(op.top()) < pri(s[i])) {
                        op.push(s[i]);
                    } else if(s[i] == ')') {
                        while(op.top() != '(') {
                            cal();
                        } 
                        op.pop();
                    } else {
                        while (!op.empty() && pri(op.top()) <= pri(s[i])) {
                            cal()
                        };
                        op.push(s[i]);
                    }
                }
            }
            if (!ss.empty()) num.push(stoi(ss));
            while(!op.empty()) cal();
            return num.top();
        }
};

void test_case_3(Solution So) {
    char str[] = "(1+(4+5+2)-3)+(6+8)";
    cout << "计算结果：" << So.calculate(str) << endl;
}

int main () {
    Solution So;
    test_case_3(So);
}
