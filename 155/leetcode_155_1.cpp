#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 用两个栈实现最小栈功能
// 一个栈s存放数据，另一个栈min存放前栈中最小的数据
class MinStack {
    public:
        stack<int> s;       // 数据栈
        stack<int> min;     // 辅助栈

        /** initialize your data structure here. */
        MinStack() {
            
        }
    
        void push(int x) {
            s.push(x);
            if (min.empty() || x < min.top()) {
                min.push(x);
            }
        }
    
        void pop() {
            
            if (s.top() == min.top()) {
                min.pop();
            }
            s.pop();
        }
    
        int top() {
            return s.top();
        }
    
        int getMin() {
            return min.top();
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