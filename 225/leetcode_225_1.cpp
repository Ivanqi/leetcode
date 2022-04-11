#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class MyStack {
    public:
        queue<int> Q1;
        queue<int> Q2;
        MyStack() {

        }
        
        void push(int x) {
           Q2.push(x);
            while (!Q1.empty()) {
               Q2.push(Q1.front());
               Q1.pop();
            }
           swap(Q1, Q2);
        }
        
        int pop() {
            int r = Q1.front();
            Q1.pop();
            return r;
        }
        
        int top() {
            return Q1.front();
        }
        
        bool empty() {
            return Q1.empty();
        }
};
