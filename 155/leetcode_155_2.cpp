#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * 一个栈实现
 * 栈中两个数据位合成一个单元，第一个数据位存放当前数据到末尾的最小值，第二个数据位存放当前数据
 */
class MinStack {
    public:
        stack<int> s;       // 数据栈

        /** initialize your data structure here. */
        MinStack() {
            
        }
    
        void push(int x) {
            if (s.empty()) {
                s.push(x);
                s.push(x);
            } else {
                int temp = s.top();
                s.push(x);
                if (x < temp) {
                    s.push(x);
                } else {
                    s.push(temp);
                }
            }
        }
    
        void pop() {
            s.pop();
            s.pop();
        }
    
        int top() {
            int temp = s.top();
            s.pop();
            int top = s.top();
            s.push(temp);
            return top;
        }
    
        int getMin() {
            return s.top();
        }
};

int main () {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "minStack minVal:" << minStack.getMin() << endl;

    minStack.pop();
    
    cout << "minStack topVal:" << minStack.top() << endl;

    cout << "minStack minVal:" << minStack.getMin() << endl;
}