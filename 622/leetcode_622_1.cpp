#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        MyCircularQueue(int k) {
            MAXSIZE = k + 1;
            Q.resize(k + 1);
            front = rear = 0;
        }
        
        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value) {
           if (isFull()) return false;
            else {
               rear = (rear + 1) % MAXSIZE;
               Q[rear] = value;
               return true;
            }
        }
        
        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) return false;

            front = (front + 1) % MAXSIZE;
            return true;
        }
        
        /** Get the front item from the queue. */
        int Front() {
            if (isEmpty()) return -1;
            else {
                return Q[(front + 1) % MAXSIZE];
            }
        }
        
        /** Get the last item from the queue. */
        int Rear() {
             if (isEmpty()) return -1;
            else {
                return Q[rear];
            }
        }
        
        /** Checks whether the circular queue is empty or not. */
        bool isEmpty() {
            if (rear == front) return true;
            else return false;
        }
        
        /** Checks whether the circular queue is full or not. */
        bool isFull() {
            if ((rear + 1) % MAXSIZE == front) return true;
            else return false;
        }
    private:
        vector<int> Q;
        int front, rear;
        int MAXSIZE;
};


int main () {
    MyCircularQueue circularQueue(3);

    cout << "enQueue: " << circularQueue.enQueue(1) << endl;
    cout << "enQueue: " << circularQueue.enQueue(2) << endl;
    cout << "enQueue: " << circularQueue.enQueue(3) << endl;
    cout << "enQueue: " << circularQueue.enQueue(4) << endl;


    cout << "Rear: " << circularQueue.Rear() << endl;
    
    cout << "isFull: " << circularQueue.isFull() << endl;
    cout << "deQueue: " << circularQueue.deQueue() << endl;
    cout << "enQueue: " << circularQueue.enQueue(4) << endl;

    cout << "Rear: " << circularQueue.Rear() << endl;
}