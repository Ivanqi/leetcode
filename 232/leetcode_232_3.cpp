#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    public:
        stack<int> iS;
        stack<int> oS;
    public:
        MyQueue() {

        }

        void in2out() {
            while (!iS.empty()) {
                oS.push(iS.top());
                iS.pop();
            }
        }
        
        void push(int x) {
            iS.emplace(x);
        }
        
        int pop() {
            if (oS.empty()) {
                in2out();
            }
            int x = oS.top();
            oS.pop();
            return x;
        }
        
        int peek() {
            if (oS.empty()) {
                in2out();
            }
            return oS.top();
        }
        
        bool empty() {
            return iS.empty() && oS.empty();
        }
    };