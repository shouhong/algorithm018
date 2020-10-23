#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int* data;
    int front;
    int rear;
    int size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data = new int[k+1];
        front = 1;
        rear = 0;
        size = k+1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        data[front] = value;
        front = (front + 1) % size;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear -1 + size) % size;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front -1 + size) % size;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear + 1) % size;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[(front-1+size)%size];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return data[(rear+1)%size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == (rear+1) % size;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return front == rear;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			                // 返回 true
circularDeque.insertLast(2);			                // 返回 true
circularDeque.insertFront(3);			                // 返回 true
circularDeque.insertFront(4);			                // 已经满了，返回 false
circularDeque.getRear();  				                // 返回 2
circularDeque.isFull();				                    // 返回 true
circularDeque.deleteLast();			                    // 返回 true
circularDeque.insertFront(4);			                // 返回 true
circularDeque.getFront();				                // 返回 4
 */
int main() {
    MyCircularDeque* circularDeque = new MyCircularDeque(3); // 设置容量大小为3
    cout << "expected result: 1, result: " << circularDeque->insertLast(1) << endl;    // 返回 true
    cout << "expected result: 1, result: " << circularDeque->insertLast(2) << endl;	   // 返回 true
    cout << "expected result: 1, result: " << circularDeque->insertFront(3) << endl;   // 返回 true
    cout << "expected result: 0, result: " << circularDeque->insertFront(4) << endl;   // 已经满了，返回 false
    cout << "expected result: 2, result: " << circularDeque->getRear() << endl;  	   // 返回 2
    cout << "expected result: 1, result: " << circularDeque->isFull() << endl;		   // 返回 true
    cout << "expected result: 1, result: " << circularDeque->deleteLast() << endl;	   // 返回 true
    cout << "expected result: 1, result: " << circularDeque->insertFront(4) << endl;   // 返回 true
    cout << "expected result: 4, result: " << circularDeque->getFront() << endl;	   // 返回 4

    return 0;
}