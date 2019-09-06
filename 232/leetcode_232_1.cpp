#include <iostream>
using namespace std;

class MyQueue {
    private:
        int count;
        struct LinkedNode
        {
            int data;
            LinkedNode *prev, *next;
        };
        LinkedNode *head;
        LinkedNode *tail;
    public:
        /** Initialize your data structure here. */
        MyQueue() {
            count = 0;
            head = NULL;
            tail = NULL;
        }
        
        /** Push element x to the back of queue. */
        void push(int x) {

            if (head == NULL) {
                head = new LinkedNode();
                head->data = x;
                tail = head;
            } else {
                tail->next = new LinkedNode();
                tail->next->data = x;
                tail->next->prev = tail;
                tail->next->next = head;
                tail = tail->next;

                head->prev = tail;
            }
            count++;
            cout << "push data: " << x << endl;
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            if (count == 0 || head == NULL) {
                cout << "Stack is empty , pop fail" << endl;
                return -1;
            } else {
                LinkedNode *temp = head;
                int data = temp->data;
                if (temp->prev == NULL || temp->next == NULL) {
                    head = tail = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    head = temp->next; 
                }
                delete temp;
                this->count--;
                return data;
            }
        }
        
        /** Get the front element. */
        int peek() {
            if (count == 0 || head == NULL) {
                cout << "Stack is empty , pop fail" << endl;
                return -1;
            } else {
                return head->data;
            }
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return this->count <= 0 ? true : false;
        }

        void print() {
            LinkedNode *cur = this->head;
            while (true) {
                cout << "print val: " << cur->data << endl;
                if (cur == this->tail) break;
                cur = cur->next;
            }
        }
};

void test_stack() 
{
    MyQueue q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.print();
    // cout << "peek val:" << q.peek() << endl;
    cout << "pop val:" << q.pop() << endl;
    // cout << "pop val:" << q.pop() << endl;
    // q.push(4);
    // cout << "pop val:" << q.pop() << endl;
    // cout << "pop val:" << q.pop() << endl;
    cout << "is empty:" << q.empty() << endl;
}

int main () {

    test_stack();
    return 0;
}
